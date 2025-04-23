# DA-project2

**DDL 26/05/2025 23:59**

## Description
This programming assignment focuses on the Delivery Truck Pallet Packing Optimization Problem, a real-world variation of the 0/1 knapsack Problem (0/1 KP). The goal is to optimize the packing of pallets in a delivery truck to maximize profit while respecting the truck’s maximum weight capacity.

Use different algorithms approaches:
- Exhaustive (Brute-Force) Search
- Dynamic Programming
- Approximation (Greedy) Algorithms
- Integer Linear Programming

## Data
Data used in the project is inside the `data` folder. A datset is structed as 2 CSV files: `TruckAndPallets_[X].csv` and `Pallets_[X].csv`. The first contains the truck capacity and number of pallets, while the second contains the pallets' weights and profits. The `[X]` is the identifier of the dataset.

## TODO
- [ ] T1.1 - Simple command-line menu that shows all implemented functionalities. Must be possible to choose a dataset, choose the algorithmic approach and view the reuslts. (1.0 point)
- [ ] T1.2 - Read and Parse input data. This funcionality is accessible through menu (0.5 points)
- [ ] T1.3 - Documentation using Doxygen for all implemented code. It should indicate *time **AND** space complexity for each algorithm*. (1.5 points)

- [ ] T2.1 - *Exhaustive / Brute-Force Approach*. Analyze performance of this approach. Can implement a backtracking approach to try to improve effiency. (3.0 points)
- [ ] T2.2 - *Dynamic Programming Approach*. Analyze performance of this approach. Evaluate using alternatives data structures and consider implementing a custom solution. (3.0 points)
- [ ] T2.3 - *Greedy / Approximation Approach*. Algorithm based on weight/profit ratio. Evaluate performance and fidelity of this approach. Analyze accuracy and perfomance of this approach in comparison to the previous two approaches (in small datasets). (3.0 points)
- [ ] T2.4 - *Integer Linear Programming Approach*. Should develop and analyse pur own ILP approach. Should mathematically formulate the 0/1 KP properly as an ILP. As an alternative to ILP, we can use other approach like Genetic Algortihms or a Hybrid Algorithmic approach suited to selected input datasets. Critically discuss the reason for the algorithms implemented. (2.0 points)

- [ ] T3.1 - Evaluate and compare algorithms. Test implementation on provided datasets. Measure and report the run time execution for each algorihtm and dataset, it should have a graphical representation of each perfomance. Compare the space complexity of different solutions. Compare the accuracy of different solutions. (2.0 points)

- [ ] T4.1 - Demo and Presentation. (2.0 points)