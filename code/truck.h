#ifndef TRUCK_H
#define TRUCK_H

#include <vector>

#include "pallet.h"

class Truck {
public:
    Truck(double capacity, double max_pallets);
    ~Truck();

    double get_capacity() const;
    double get_max_pallets() const;

    std::vector<Pallet> get_loaded_pallets() const;
    void load_pallet(const Pallet& pallet);

    std::vector<Pallet> get_available_pallets() const;
    void add_available_pallet(const Pallet& pallet);

private:
    double capacity;
    double max_pallets;
    std::vector<Pallet> loaded_pallets;
    std::vector<Pallet> available_pallets;        // n é definitivo (vector), pq n sei como seriam os algoritmos
};

#endif