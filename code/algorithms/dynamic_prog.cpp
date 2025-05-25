#include "dynamic_prog.h"
#include <vector>
#include <chrono>

bool is_better_dp_solution(double new_val, const std::vector<int>& new_indices,
                           double old_val, const std::vector<int>& old_indices) {
    if (new_val > old_val) return true;
    if (new_val < old_val) return false;

    // Desempate 1: menor número de pallets
    if (new_indices.size() < old_indices.size()) return true;
    if (new_indices.size() > old_indices.size()) return false;

    // Desempate 2: ordem lexicográfica dos índices
    for (size_t i = 0; i < new_indices.size(); ++i) {
        if (new_indices[i] < old_indices[i]) return true;
        if (new_indices[i] > old_indices[i]) return false;
    }

    return false;
}

static const auto TIME_LIMIT = std::chrono::microseconds(90000000);

ReturnResult dp_packing(const Truck& truck, std::chrono::microseconds& total_duration, bool& isValidRun) {

    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<Pallet> available_pallets = truck.get_available_pallets();
    int n = available_pallets.size();
    int truck_capacity = truck.get_capacity();

    // array de programação dinâmica, para cada índice (capacidade), guarda-se o melhor valor de paletes
    std::vector<double> dp_array(truck_capacity + 1, 0);

    // vetor 2D, mantém info das paletes usadas para cada capacidade
    std::vector<std::vector<int>> selected_pallets(truck_capacity + 1);


    for (int i = 0; i < n; i++) {
        int weight = available_pallets[i].get_weight();
        double val = available_pallets[i].get_value();

        // como se usa um array 1D, de forma a comparar corretamente com items da linha anterior, a leitura começa pela capacidade máxima
        // só é preciso atualizar os valores quando a capacidade >= peso da palete a verificar
        for (int w = truck_capacity; w >= weight; w--) {
            double new_val = dp_array[w - weight] + val;
            if (is_better_dp_solution(new_val, selected_pallets[w - weight], dp_array[w], selected_pallets[w])) {
                dp_array[w] = new_val;

                // atualizar paletes usadas
                selected_pallets[w] = selected_pallets[w - weight];
                selected_pallets[w].push_back(i);
            }

            if (std::chrono::high_resolution_clock::now() - start_time >= TIME_LIMIT) {
                isValidRun = false;
                return {{}, 0,0};
            }
        }
    }

    // Reconstroi paletes selecionadas
    ReturnResult result;
    result.total_value = dp_array[truck_capacity];
    result.total_weight = 0.0;

    for (int idx : selected_pallets[selected_pallets.size() - 1]) {
        result.pallets.push_back(available_pallets[idx]);
        result.total_weight += available_pallets[idx].get_weight();
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    total_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    return result;
}


