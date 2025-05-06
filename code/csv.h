#ifndef CSV_H
#define CSV_H

#include <string>
#include <vector>

class Csv {
    public:
        std::vector<std::vector<std::string>> getData();
        void readCSV(const std::string& file_name);
    private:
        std::vector<std::vector<std::string>> data;     // where the csv data is stored
};

#endif