//
// Created by Rafael dos Santos Rodrigues on 12/05/2025.
//

#include "brute_force.h"
#include <algorithm>

//brute force
std::vector<Pallet> brute_force_packing(const Truck& truck) {

    std::vector<Pallet> available_pallets = truck.get_available_pallets();
    int truck_capacity = truck.get_capacity();

    int n = available_pallets.size();
    int bit_mask;

    std::vector<Pallet> best_subset;
    double max_value = 0.0;

    //o numero maximo de combinações de paletes possivel de fazer é 2^n (sendo n o numero de paletes disponiveis)
    int all_combinations = 1 << n;

    //percorrer todas as combinações
    for (int combination_nr = 0; combination_nr < all_combinations; combination_nr++) {

        //criar um subset para guardar a combinação de paletes
        std::vector<Pallet> subset;
        double current_weight = 0.0;
        double current_value = 0.0;

        //logica de bits ativos no vetor subset para testar todas as combinações ativando o index da palete
        for (int pallet_index = 0; pallet_index < n; pallet_index++) {

            bit_mask = 1 << pallet_index;

            //verifica se a combinação atual inclui a palete atraves dos bits ativos em combination_nr
            if (combination_nr & bit_mask) {

                //se sim, ir "buscar" a palete correspondente ao index, atualizar oa valores e adicionar ao vetor
                const Pallet& p = available_pallets[pallet_index];
                current_weight += p.get_weight();
                current_value += p.get_value();
                subset.push_back(p);
            }
        }

        //antes de atualizar como "melhor escolha" temos de ver se o peso é suportado, se o numero de paletes do subset
        //é menor que o numero maximo de paletes suportado e se o valor atual é melhor que o maior valor até agora
        if ((current_weight <= truck_capacity) && (current_value > max_value)) {

            max_value = current_value;
            best_subset = subset;
        }
    }

    return best_subset;
}


//backtracking