#ifndef DYNAMIC_PROG_H
#define DYNAMIC_PROG_H

#include <vector>
#include <chrono>
#include "../app.h"
#include "../data_structures/truck.h"
#include "../data_structures/pallet.h"

ReturnResult dp_packing(const Truck& truck, std::chrono::microseconds& total_duration, bool& isValidRun);

bool is_better_dp_solution(double new_val, const std::vector<int>& new_indices,
                           double old_val, const std::vector<int>& old_indices);

#endif //DYNAMIC_PROG_H
