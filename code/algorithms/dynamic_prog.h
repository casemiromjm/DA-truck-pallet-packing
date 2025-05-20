//
// Created by sebas on 16/05/2025.
//

#ifndef DYNAMIC_PROG_H
#define DYNAMIC_PROG_H

#include <vector>
#include <chrono>
#include "../truck.h"
#include "../data_structures/pallet.h"

std::vector<Pallet> dp_packing(const Truck& truck, std::chrono::microseconds* total_duration);


#endif //DYNAMIC_PROG_H
