//
// Created by Rafael dos Santos Rodrigues on 20/05/2025.
//

#ifndef GRAPH_CONSTRUCT_H
#define GRAPH_CONSTRUCT_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <string>


#include "../utils/csv.h"
#include "../app.h"

Truck load_truck_from_dataset(int dataset_number);
void construct_data_csv(int num_datasets = 4, int num_runs = 10);

#endif //PERFORMANCE_DATA_H
