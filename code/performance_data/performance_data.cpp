#include "performance_data.h"

#include "../algorithms/brute_force.h"
#include "../algorithms/dynamic_prog.h"
#include "../algorithms/greedy.h"
#include "../data_structures/truck.h"
#include "../app.h"
#include <fstream>
#include <chrono>

static const int SOLUTION_CALLS = 10;
static const std::string OUTPUT_PATH = "../../performance_analysis/data/";

void generate_performance_csv(App& app) {

    // loop through all (implemented) algorithms
    for (int alg = 1; alg <= 4; alg++) {

        app.set_algorithm((App::Algorithm)alg);

        // prepare file
        std::string out_file;
        switch ((App::Algorithm)alg) {
            case App::Algorithm::BRUTE_FORCE:
                out_file = OUTPUT_PATH + "bruteforce_report.csv";
                break;

            case App::Algorithm::BRUTE_FORCE_BACKTRACKING:
                out_file = OUTPUT_PATH + "bruteforce_backtracking_report.csv";
                break;

            case App::Algorithm::DYNAMIC:
                out_file = OUTPUT_PATH + "dynamicprog_report.csv";
                break;

            case App::Algorithm::GREEDY:
                out_file = OUTPUT_PATH + "greedy_report.csv";
                break;
        }
        std::ofstream csv_out (out_file);
        csv_out << "Dataset,TimeMicroseconds,NumberPallets\n";

        // loop through all (example) datasets
        for (int d = 1; d <= 10; d++) {

            app.set_dataset((App::Dataset)d);
            app.read_dataset();
            auto truck = app.get_truck();

            std::chrono::microseconds helper_duration{0};
            std::chrono::microseconds total_duration{0};

            int valid_runs = SOLUTION_CALLS;        // valid_runs precisa ser atualizada a medida q alguma run n é válida
            for (int i = 0; i < SOLUTION_CALLS; i++) {
                bool isValidRun = true;

                switch ((App::Algorithm)alg) {
                    case App::Algorithm::BRUTE_FORCE:
                        brute_force_packing(truck, helper_duration, isValidRun);
                        break;

                    case App::Algorithm::BRUTE_FORCE_BACKTRACKING:
                        brute_force_backtracking(truck, helper_duration, isValidRun);
                        break;

                    case App::Algorithm::DYNAMIC:
                        dp_packing(truck, helper_duration, isValidRun);
                        break;

                    case App::Algorithm::GREEDY:
                        greedy_packing(truck, helper_duration, isValidRun);
                        break;
                }
                if (!isValidRun) {
                    --valid_runs;
                }

                total_duration += helper_duration;
            }

            long long avg_time = 0;
            if (valid_runs > 0) {
                avg_time = total_duration.count() / valid_runs;
            }

            csv_out << "Dataset" << d << "," << avg_time << "," << truck.get_num_pallets() << "\n";
        }

        csv_out.close();
    }
}
