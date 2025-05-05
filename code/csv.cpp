#include "csv.h"

#include <fstream>
#include <iostream>
#include <sstream>

/*!
 * Access the CSV data
 * @return CSV data
 */
std::vector<std::vector<std::string>> Csv::getData() {
    return data;
}

/*!
 * Reads CSV files and storing it
 * @param file_name file name that you are trying to open
 * @return all lines in a 2D vector
 */
void Csv::readCSV(const std::string& file_name) {
    std::ifstream file(file_name);

    data.clear();

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << file_name << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);       // skips the header line
    while (getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        data.push_back(row);
    }

    file.close();
}

void Csv::read_dataset(const int &dataset_id) {
    //TODO
}

