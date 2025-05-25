#ifndef DYNAMIC_PROG_H
#define DYNAMIC_PROG_H

#include <vector>
#include <chrono>
#include "../app.h"
#include "../data_structures/truck.h"
#include "../data_structures/pallet.h"

ReturnResult dp_packing(const Truck& truck, std::chrono::microseconds& total_duration);

#endif //DYNAMIC_PROG_H
