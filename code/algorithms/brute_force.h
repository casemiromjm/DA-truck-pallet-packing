#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H

#include <vector>
#include <chrono>
#include "../data_structures/truck.h"
#include "../data_structures/pallet.h"


std::vector<Pallet> brute_force_packing(const Truck& truck, std::chrono::microseconds* total_duration);

std::vector<Pallet> backtracking_pallet_packing(Truck& truck);

#endif //BRUTE_FORCE_H
