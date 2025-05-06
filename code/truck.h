#ifndef TRUCK_H
#define TRUCK_H

class Truck {
public:
    Truck(double capacity, double max_pallets);
    ~Truck();
    double get_capacity() const;
    double get_max_pallets() const;

private:
    double capacity;
    double max_pallets;
};

#endif