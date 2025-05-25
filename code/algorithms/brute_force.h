#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H

#include <vector>
#include <chrono>
#include "../app.h"
#include "../data_structures/truck.h"
#include "../data_structures/pallet.h"


ReturnResult brute_force_packing(const Truck& truck, std::chrono::microseconds& total_duration);

ReturnResult brute_force_backtracking(const Truck& truck, std::chrono::microseconds& total_duration);

void backtrack(const std::vector<Pallet>& pallets, int index, double current_weight, double current_value, int max_capacity,
    std::vector<Pallet>& current_solution, std::vector<Pallet>& best_solution, double& best_value);

#endif //BRUTE_FORCE_H
