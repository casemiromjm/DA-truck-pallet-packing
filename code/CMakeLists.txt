cmake_minimum_required(VERSION 3.28)
project(truck-pallet-packing)

set(CMAKE_CXX_STANDARD 20)

add_executable(truck-pallet-packing main.cpp
        menu/menu.cpp
        menu/state.cpp
        menu/ui_flow.cpp
        utils/csv.cpp
        data_structures/truck.cpp
        data_structures/pallet.cpp
        app.cpp
        algorithms/brute_force.cpp
        algorithms/dynamic_prog.cpp
        algorithms/greedy.cpp
        performance_data/performance_data.cpp
)
