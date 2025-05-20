//
// Created by sebas on 16/05/2025.
//

#include "dynamic_prog.h"
#include <vector>
#include <algorithm>

std::vector<Pallet> dp_packing(const Truck& truck) {
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
            if (new_val > dp_array[w]) {
                dp_array[w] = new_val;

                // atualizar paletes usadas
                selected_pallets[w] = selected_pallets[w - weight];
                selected_pallets[w].push_back(i);
            }
        }
    }

    // Reconstroi paletes selecionadas
    std::vector<Pallet> best_subset;
    for (int idx : selected_pallets[selected_pallets.size() - 1]) {
        best_subset.push_back(available_pallets[idx]);
    }

    return best_subset;
}


