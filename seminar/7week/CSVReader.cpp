#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class CSVReader{
private:
    std::vector<std::vector<std::string>> data;
public:
    CSVReader() = default;
    CSVReader(auto d) : data(d){}


    friend std::istream& operator>>(std::istream& is, CSVReader& obj)
    {
        std::string line;
        while (std::getline(is,line)) {
            std::vector<std::string> row;
            std::stringstream ss(line);
            std::string cell;
            while (std::getline(ss, cell, ',')) {
                row.push_back(cell);
            }
            obj.data.push_back(row);
        }
    }



    friend std::ostream& operator<<(std::ostream& os, const CSVReader& obj)
    {
        std::string line;
        for (auto row : obj.data) {
            for (int i=0; i < row.size() ; ++i) {
                if (i !=0) os << ",";
                 os << row[i];
            }
            os << "\n";
        }
        return os;
    }
};