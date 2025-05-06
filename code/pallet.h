#ifndef PALLET_H
#define PALLET_H

class Pallet {
public:
    Pallet(int id, double weight, double value);
    ~Pallet();
    int get_id() const;
    double get_weight() const;
    double get_value() const;
    void calculate_weight_value_ratio();
    double get_weight_value_ratio() const;

private:
    int id;
    double weight;
    double value;
    double weight_value_ratio;       // useful for greedy approach
};

#endif