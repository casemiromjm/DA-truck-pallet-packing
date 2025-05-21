#ifndef PERFORMANCE_DATA_H
#define PERFORMANCE_DATA_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <string>


#include "../utils/csv.h"
#include "../app.h"

#define SOL_CALLS 10

Truck load_truck_from_dataset(int dataset_number);      // é a funcao readme
void generate_performance_csv(int num_datasets = 4, int num_runs = SOL_CALLS);

#endif //PERFORMANCE_DATA_H
