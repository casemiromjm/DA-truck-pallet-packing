#include "pallet.h"

Pallet::Pallet(int id, double weight, double value) {
    this->id = id;
    this->weight = weight;
    this->value = value;
    weight_value_ratio = 0;
}

Pallet::~Pallet() = default;

int Pallet::get_id() const {
    return id;
}

double Pallet::get_weight() const {
    return weight;
}

double Pallet::get_value() const {
    return value;
}

void Pallet::calculate_weight_value_ratio() {
    weight_value_ratio = value / weight;
}

double Pallet::get_weight_value_ratio() const {
    return weight_value_ratio;
}

