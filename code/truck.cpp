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
