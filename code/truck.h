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
    std::vector<Pallet> get_pallets() const;
    void add_pallet(const Pallet& pallet);

private:
    double capacity;
    double max_pallets;
    std::vector<Pallet> pallets;        // n é definitivo (vector), pq n sei como seriam os algoritmos
};

#endif