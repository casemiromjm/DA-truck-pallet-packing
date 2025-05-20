#ifndef TRUCK_H
#define TRUCK_H

#include <vector>

#include "pallet.h"

class Truck {
public:
    Truck(double capacity, double max_pallets);
    ~Truck();

    int get_capacity() const;
    int get_num_pallets() const;

    std::vector<Pallet> get_available_pallets() const;
    void add_available_pallet(const Pallet& pallet);

private:
    double capacity;
    double num_pallets;
    std::vector<Pallet> available_pallets;        // n é definitivo (vector), pq n sei como seriam os algoritmos
};

#endif