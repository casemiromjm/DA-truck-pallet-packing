# Truck Pallet Packing Optimization Tool

## Description
This tool works as a simple way to handle the Delivery Truck Pallet Packing Optimization Problem, a real-world variation of the 0/1 knapsack Problem (0/1 KP). The goal is to optimize the packing of pallets in a delivery truck to maximize profit while respecting the truck’s maximum weight capacity.

Use different algorithms approaches:
- Exhaustive (Brute-Force) Search
- Dynamic Programming
- Approximation (Greedy) Algorithms

## Data
Data used in the project is inside the `data` folder. A datset is structed as 2 CSV files: `TruckAndPallets_[X].csv` and `Pallets_[X].csv`. The first contains the truck capacity and number of pallets, while the second contains the pallets' weights and profits. The `[X]` is the identifier of the dataset.

## How to run
```
git clone git@github.com:casemiromjm/DA-truck-pallet-packing.git
cd DA-truck-pallet-packing
mkdir build && cd build
```

If you have `ninja` installed, you can use it to build the project:
```
cmake ../code
ninja
./truck-pallet-packing
```

Otherwise, you can use `make`:
```
cmake -G "Unix Makefiles" ../code
make
./truck-pallet-packing
```

## Output
The program will output the result for the selected algorithm and dataset. It will display the total profit, the total weight and the pallets selected for packing.
