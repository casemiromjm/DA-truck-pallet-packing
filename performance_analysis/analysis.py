import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

BRUTEFORCE_DATA = "./data/bruteforce_report.csv"
DYNAMICPROG_DATA = "./data/dynamicprog_report.csv"
GREEDY_DATA = "./data/greedy_report.csv"

def plot_algorithm(algorithm_data, algorithm_name : str, color : str):
    plt.style.use('seaborn-v0_8')
    plt.figure(figsize=(10, 6))

    algorithm_data = algorithm_data.sort_values("NumberPallets")
    x = algorithm_data["NumberPallets"]
        
    plt.plot(x, algorithm_data["TimeMicroseconds"],
            marker='o',
            markersize=8,
            color=color,
            linewidth=2,
            alpha=0.8)
    
    # add data labels
    for (xi, yi) in (zip(x, algorithm_data["TimeMicroseconds"])):
        plt.annotate(f"{int(yi)}µs", 
                    (xi, yi),
                    textcoords="offset points",
                    xytext=(0, 10),
                    ha='center',
                    fontsize=9)
    
    # Customize chart
    plt.title(f"{algorithm_name} Performance", pad=20, fontsize=14)
    plt.xlabel("Number of Pallets", labelpad=10, fontsize=12)
    plt.ylabel("Execution Time (µs)", labelpad=10, fontsize=12)
    plt.xticks(x)
    plt.grid(True, alpha=0.3)
    
    plt.tight_layout()
    plt.savefig(f"./output/{algorithm_name.lower().replace(' ', '')}_performance.png")
    plt.close()
        
def plot_combined(algorithms_data):

    plt.figure(figsize=(12, 7))
    
    x = range(len(algorithms_data[0]["data"]["Dataset"]))
    
    for algorithm in algorithms_data:
        data = algorithm["data"]
        plt.plot(x, data["TimeMicroseconds"],
                marker='o',
                linewidth=2,
                markersize=8,
                color=algorithm["color"],
                label=algorithm["name"])
    
    plt.title("Algorithm Performance Comparison (Line Chart)")
    plt.xlabel("Dataset")
    plt.ylabel("Execution Time (µs)")
    plt.xticks(x, algorithms_data[0]["data"]["Dataset"], rotation=45)
    plt.legend()
    plt.grid(True, alpha=0.3)
    
    # highlight fastest algorithm at each point
    for i in x:
        times = [alg["data"]["TimeMicroseconds"].iloc[i] for alg in algorithms_data]
        min_time = min(times)
        plt.annotate("★", (i, min_time), 
                    ha='center', va='bottom',
                    fontsize=14, color='gold')
    
    plt.tight_layout()
    plt.savefig("./output/algorithms_comparison.png")
    plt.close()

def load_data():
    alg = [
        ("Brute Force", "red", BRUTEFORCE_DATA),
        ("Dynamic Programming", "green", DYNAMICPROG_DATA),
        ("Greedy", "blue", GREEDY_DATA)
    ]

    valid_data = []
    
    for (name, color, path) in alg:
        data = pd.read_csv(path)
        data["TimeMicroseconds"] = pd.to_numeric(data["TimeMicroseconds"])

        data.sort_values("TimeMicroseconds")

        plot_algorithm(data, name, color)

        valid_data.append({
            "data": data,
            "name": name,
            "color": color
        })

    return valid_data

def main():

    algorithms_data = load_data()

    # commented pq n fica uma visualização de fato util por conta da escala
    #plot_combined(algorithms_data)

    for alg in algorithms_data:
        plot_algorithm(alg["data"], alg["name"], alg["color"])

if __name__ == "__main__":
    main()
