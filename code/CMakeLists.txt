cmake_minimum_required(VERSION 3.30)
project(code)

set(CMAKE_CXX_STANDARD 20)

add_executable(code main.cpp
        menu.cpp
        state.cpp
        ui_flow.cpp
        csv.cpp
        truck.cpp
        pallet.cpp
        app.cpp
)
