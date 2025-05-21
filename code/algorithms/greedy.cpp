#include <vector>
#include <algorithm>
#include <chrono>
#include "greedy.h"


// Função auxiliar de comparar rácios valor/peso das paletes
bool compare_ratio(const Pallet& a, const Pallet& b) {
    if(a.get_weight_value_ratio() == b.get_weight_value_ratio()){
      return a.get_weight() > b.get_weight();
    }

    return a.get_weight_value_ratio() > b.get_weight_value_ratio();
}

std::vector<Pallet> greedy_packing(const Truck& truck, std::chrono::microseconds& total_duration) {

    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<Pallet> available_pallets = truck.get_available_pallets();
    std::vector<Pallet> best_subset;

    double remaining_capacity = truck.get_capacity();
    int max_pallets = truck.get_num_pallets();

    // Calcular ratios
    for (Pallet& pallet : available_pallets) {
        pallet.calculate_weight_value_ratio();
    }

    // Sorting com a booleana de comparar rácios
    std::sort(available_pallets.begin(), available_pallets.end(), compare_ratio);

    // Escolher de forma "gulosa" as paletes até não caberem mais
    for (const Pallet& pallet : available_pallets) {
        if (pallet.get_weight() <= remaining_capacity && best_subset.size() < max_pallets) {
            best_subset.push_back(pallet);
            remaining_capacity -= pallet.get_weight();
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    total_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    return best_subset;
}
