#include <string>
#include <cmath>
#include <iostream>
#include <vector>
class Reportable {
public:
    virtual void printShortReport() const =0;
protected:
    virtual ~Reportable() = default;
};

class Employee : public Reportable {
protected:
    std::string name;
    int id;
public:
    Employee(const std::string& n, int i) : name(n), id(i) {}
    virtual double calculatePay() const =0;
    virtual std::string getRole() const =0;
    virtual void printInfo() const =0;
    virtual bool isManager() const =0;
    void printShortReport() const {
        std::cout << id << name << getRole() << std::endl;
    }
    virtual ~Employee() = default;
};

class SalariedEmployee : public Employee {
protected:
    double monthlySalary;
public:
    SalariedEmployee(const std::string& n, int i, double salary) : Employee(n, i), monthlySalary(salary) {}
    double calculatePay() const override { return monthlySalary; }
    std::string getRole() const override { return "SalariedEmployee"; }
    void printInfo() const override{
        std::cout << id << ' ' << name << ' ' << getRole() << ' ' << monthlySalary << std::endl;

    }
    bool isManager() const override { return false; }
};

class HourlyEmployee: public Employee {
protected:
    double hourlyRate;
    double hoursWorked;
public:
    HourlyEmployee(const std::string& n, int i, double hourly, double hours) : Employee(n,i), hourlyRate(hourly), hoursWorked(hours){}
    double calculatePay() const override{return hourlyRate + hoursWorked;}
    std::string getRole() const override{return "HourlyEmployee";}
    void printInfo() const override {
        std::cout << id << ' ' << name << ' ' << getRole() << ' ' << hourlyRate <<" "<< hoursWorked<< std::endl;
    }
};

class Manager: public SalariedEmployee {
protected:
    double bonus;
public:
    Manager(const std::string&n, int i,double salary, double b) : SalariedEmployee(n,i, salary), bonus(b){}
    double calculatePay() const override{return monthlySalary + bonus;}
    std::string getRole() const override{return "bonus";}
    void printInfo() const override {
        std::cout << id << ' ' << name << ' ' << getRole() << ' ' <<monthlySalary<<" "<< bonus << std::endl;
    }
    bool isManager() const override{return true;}
};

class Company {
protected:
    std::vector<Employee*> employees;
public:
    void addEmployee(Employee* e) {
        for (auto e:employees) {
            std::cout << e << ' ';
        }
        std::cout <<'\n';
    }
    void printAllEmployees() const {
        for (auto e:employees) {
            std::cout << e << ' ';
        }
        std::cout <<'\n';
    }
    void printAllShortReports() const;
    double calculateTotalPayroll() const;
    int countManagers() const;

};

int main() {
}