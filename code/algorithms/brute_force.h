//
// Created by Rafael dos Santos Rodrigues on 12/05/2025.
//

#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H

#include <vector>
#include "../truck.h"
#include "../pallet.h"


std::vector<Pallet> brute_force_packing(const Truck& truck);

std::vector<Pallet> backtracking_pallet_packing(Truck& truck);

#endif //BRUTE_FORCE_H
