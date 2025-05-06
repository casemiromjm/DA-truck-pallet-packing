#include "truck.h"

Truck::Truck(double capacity, double max_pallets) {
    this->capacity = capacity;
    this->max_pallets = max_pallets;
}

Truck::~Truck() = default;

double Truck::get_capacity() const {
    return capacity;
}

double Truck::get_max_pallets() const {
    return max_pallets;
}

std::vector<Pallet> Truck::get_pallets() const {
    return pallets;
}

void Truck::add_pallet(const Pallet& pallet) {
    this->pallets.push_back(pallet);
}
