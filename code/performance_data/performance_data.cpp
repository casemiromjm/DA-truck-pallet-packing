//
// Created by Rafael dos Santos Rodrigues on 20/05/2025.
//

#include "performance_data.h"
#include "../algorithms/brute_force.h"
#include "../algorithms/dynamic_prog.h"
#include "../data_structures/truck.h"
#include "../app.h"



Truck load_truck_from_dataset(int dataset_number) {
    Csv file;

    std::string dataset_num = App::convert_num_str(dataset_number);

    file.readCSV("../data/datasets/TruckAndPallets_" + dataset_num + ".csv");
    Truck t(std::stod(file.getData()[0][0]), std::stod(file.getData()[0][1]));

    file.readCSV("../data/datasets/Pallets_" + dataset_num + ".csv");
    for (auto& pallet : file.getData()) {
        Pallet p(std::stoi(pallet[0]), std::stod(pallet[1]), std::stod(pallet[2]));
        t.add_available_pallet(p);
    }

    return t;
}

void construct_data_csv(int num_datasets, int num_runs) {
    std::ofstream csv_out("../performance_data/data.csv");

    csv_out << "Dataset, TimeMicroseconds, NumberPallets\n";

    for (int d = 1; d <= num_datasets; ++d) {
        Truck truck = load_truck_from_dataset(d);

        std::chrono::microseconds helper_duration{0};
        std::chrono::microseconds total_duration{0};

        for (int i = 0; i < num_runs; ++i) {

            dp_packing(truck, &helper_duration);

            total_duration += helper_duration;
        }

        auto avg_time = total_duration.count() / num_runs;

        csv_out << "Dataset" << d << "," << avg_time << "," << truck.get_num_pallets() << "\n";
    }

    csv_out.close();
}
