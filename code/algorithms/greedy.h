#ifndef GREEDY_H
#define GREEDY_H

#include <chrono>
#include <vector>
#include "../data_structures/truck.h"
#include "../data_structures/pallet.h"

std::vector<Pallet> greedy_packing(const Truck& truck, std::chrono::microseconds& total_duration);

bool compare_ratio(const Pallet& a, const Pallet& b);

#endif //GREEDY_H
