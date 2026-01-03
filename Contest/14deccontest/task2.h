#include <climits>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using UnixTS = unsigned int;

const unsigned short TRANSACTION_COL_N = 6;
const unsigned short ACCOUNT_COL_N = 3;

struct Transaction {
    std::string id;
    UnixTS date;
    std::string type;
    std::string from;
    std::string to;
    double amount;
    bool operator<(const Transaction& other) const;
};

struct Account {
    Account();
    Account(const std::string& id, const std::string& name, UnixTS validity_dt = UINT_MAX);
    void addTransaction(const Transaction& transaction);
    double getBalance(UnixTS = UINT_MAX) const;
    void printInfo() const;
    size_t getTransactionsCount() const;

    std::string id;
    std::string name;
    std::set<Transaction> transactions;
    UnixTS validity_dt;
};

void Account::printInfo() const
{
    std::cout << "--------------------------------\n"
              << "id: " << id << '\n'
              << "name: " << name << '\n'
              << "validity datetime: " << validity_dt << '\n'
              << "--------------------------------\n";
}

size_t Account::getTransactionsCount() const
{
    return transactions.size();
}

Account::Account()
{
    id = "00000000-0000-0000-0000-000000000000";
    name = "Noname";
    validity_dt = 0;
}

Account::Account(const std::string& id,
                 const std::string& name,
                 UnixTS validity_dt)
{
    this->id = id;
    this->name = name;
    this->validity_dt = validity_dt;
}

int getTransactionTypeWeight(const std::string& type) {
    if (type == "deposit") return 1;
    if (type == "withdraw") return 2;
    if (type == "transfer") return 3;
    return 4;
}

bool Transaction::operator<(const Transaction& other) const
{
    if (date != other.date) {
        return date < other.date;
    }
    if (type != other.type) {
        return getTransactionTypeWeight(type) < getTransactionTypeWeight(other.type);
    }
    return false;
}

void Account::addTransaction(const Transaction& transaction)
{
    transactions.insert(transaction);
}

double Account::getBalance(UnixTS timestamp) const
{
    double balance = 0;
    for (const auto& t : transactions) {
        if (t.date > timestamp) {
            continue;
        }

        if (t.type == "deposit") {
            balance += t.amount;
        } else if (t.type == "withdraw") {
            balance -= t.amount;
        } else if (t.type == "transfer") {
            if (t.from == id) {
                balance -= t.amount;
            }
            if (t.to == id) {
                balance += t.amount;
            }
        }
    }
    return balance;
}

using AccountContainer = std::unordered_map<std::string, Account>;
using TransactionContainer = std::set<Transaction>;

TransactionContainer readTransactions(std::ifstream& fileStream)
{
    TransactionContainer transactions;
    std::string line;

    if (!std::getline(fileStream, line)) return transactions;
    if (line.empty()) return transactions;

    size_t transactionsCount = 0;
    try {
        transactionsCount = std::stoul(line);
    } catch (...) {
        return transactions;
    }

    // Пропускаем заголовок CSV
    std::getline(fileStream, line);

    for (size_t k = 0; k < transactionsCount; ++k)
    {
        if (!std::getline(fileStream, line)) break;

        std::stringstream ss(line);
        std::string field;
        Transaction transaction;

        for (unsigned short i = 0; i < TRANSACTION_COL_N; i++)
        {
            if (!std::getline(ss, field, ';')) break;

            switch (i) {
                case 0: transaction.id = field; break;
                case 1: transaction.date = (UnixTS)std::stoul(field); break;
                case 2: transaction.type = field; break;
                case 3: transaction.from = field; break;
                case 4: transaction.to = field; break;
                case 5: transaction.amount = std::stod(field); break;
            }
        }
        transactions.insert(transaction);
    }

    return transactions;
}

AccountContainer readAccounts(std::ifstream& fileStream)
{
    AccountContainer accounts;
    std::string line;

    if (!std::getline(fileStream, line)) return accounts;

    size_t accountsCount = 0;
    try {
        accountsCount = std::stoul(line);
    } catch (...) {
        return accounts;
    }

    for (size_t k = 0; k < accountsCount; ++k)
    {
        if (!std::getline(fileStream, line)) break;

        std::stringstream ss(line);
        std::string field;

        std::string id;
        std::string name;
        UnixTS validity_dt = UINT_MAX;

        for (unsigned short i = 0; i < ACCOUNT_COL_N; i++)
        {
            if (!std::getline(ss, field, ';')) break;

            switch (i) {
                case 0: id = field; break;
                case 1: name = field; break;
                case 2: validity_dt = (UnixTS)std::stoul(field); break;
            }
        }
        accounts[id] = Account(id, name, validity_dt);
    }

    return accounts;
}

void fillAccounts(AccountContainer& accounts, const TransactionContainer& transactions)
{
    for (const auto& t : transactions) {
        if (t.type == "deposit") {
            if (accounts.count(t.to)) {
                accounts[t.to].addTransaction(t);
            }
        } else if (t.type == "withdraw") {
            if (accounts.count(t.from)) {
                accounts[t.from].addTransaction(t);
            }
        } else if (t.type == "transfer") {
            if (accounts.count(t.from)) {
                accounts[t.from].addTransaction(t);
            }
            if (t.from != t.to && accounts.count(t.to)) {
                accounts[t.to].addTransaction(t);
            }
        }
    }
}