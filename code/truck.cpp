#include "truck.h"

Truck::Truck(double capacity, double num_pallets) {
    this->capacity = capacity;
    this->num_pallets = num_pallets;
}

Truck::~Truck() = default;

double Truck::get_capacity() const {
    return capacity;
}

double Truck::get_num_pallets() const {
    return num_pallets;
}

std::vector<Pallet> Truck::get_available_pallets() const {
    return available_pallets;
}

void Truck::add_available_pallet(const Pallet& pallet) {
    this->available_pallets.push_back(pallet);
}
