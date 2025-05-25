#include "brute_force.h"
#include <algorithm>

static const auto TIME_LIMIT = std::chrono::microseconds(90000000);

//brute force
ReturnResult brute_force_packing(const Truck& truck, std::chrono::microseconds& total_duration, bool& isValidRun) {

    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<Pallet> available_pallets = truck.get_available_pallets();
    int truck_capacity = truck.get_capacity();

    int n = available_pallets.size();

    // checagem
    if (n >= 20) {
        isValidRun = false;
        return {{}, 0, 0};
    }

    int bit_mask;

    ReturnResult best_result;
    best_result.total_value = 0.0;
    best_result.total_weight = 0.0;

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
        if ((current_weight <= truck_capacity) && (current_value > best_result.total_value)) {

            best_result.pallets = subset;
            best_result.total_value = current_value;
            best_result.total_weight = current_weight;
        }

        if (std::chrono::high_resolution_clock::now() - start_time >= TIME_LIMIT) {
            isValidRun = false;
            return {{}, 0,0};
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    total_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    return best_result;
}


//backtracking
void backtrack(const std::vector<Pallet>& pallets, int index, double current_weight, double current_value, int max_capacity,
    std::vector<Pallet>& current_solution,  ReturnResult& best_result, bool& isValidRun, std::chrono::time_point<std::chrono::system_clock> start_time) {

    //caso base, ou seja, já percorreu todas as paletes
    if (index == pallets.size()) {

        //verificar se a solução atual é melhor
        if (current_weight <= max_capacity && current_value >  best_result.total_value) {

            //se sim, atualizar os valores
            best_result.pallets = current_solution;
            best_result.total_weight = current_weight;
            best_result.total_value = current_value;
        }
        return;
    }

    // checagem
    if (std::chrono::high_resolution_clock::now() - start_time >= TIME_LIMIT) {
        isValidRun = false;
        return;
    }

    //logica do backtracking, primeiro tentar incluir a palete atual se ele respeitar as capacidades max
    if (current_weight + pallets[index].get_weight() <= max_capacity) {

        //incluir a solução atual
        current_solution.push_back(pallets[index]);

        //chamar o backtracking atualizando o index da palete (+1 porque adicionamos 1), o peso atual (somar o da palete colocada) e o valor atual com a mesma logica
        backtrack(pallets, index + 1, current_weight + pallets[index].get_weight(), current_value + pallets[index].get_value(),
                  max_capacity, current_solution, best_result, isValidRun, start_time);

        //no fim remover a palete
        current_solution.pop_back();
    }

    //agora tentar sem incluir a palete para ver qual o melhor (neste caso so muda o index porque "saltamos" a palete
    backtrack(pallets, index + 1, current_weight, current_value, max_capacity, current_solution, best_result, isValidRun, start_time);
}

//função principal
ReturnResult brute_force_backtracking(const Truck& truck, std::chrono::microseconds& total_duration, bool& isValidRun) {

    auto start_time = std::chrono::high_resolution_clock::now();

    const auto& pallets = truck.get_available_pallets();
    int capacity = truck.get_capacity();

    ReturnResult best_result;
    std::vector<Pallet> current_solution;

    best_result.pallets = current_solution;
    best_result.total_value = 0.0;
    best_result.total_weight = 0.0;

    backtrack(pallets, 0, 0.0, 0.0, capacity, current_solution, best_result, isValidRun, start_time);

    if (!isValidRun) {
        return {{}, 0, 0};
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    total_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);


    return best_result;
}