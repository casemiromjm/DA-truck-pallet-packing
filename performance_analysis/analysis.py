import matplotlib.pyplot as plt
import pandas as pd

BRUTEFORCE_DATA = "./data/bruteforce_report.csv"
DYNAMICPROG_DATA = "./data/dynamicprog_report.csv"
GREEDY_DATA = "./data/greedy_report.csv"

def plot_algorithm(data : pd.DataFrame, algorithm_name : str, color : str):

    fig, ax = plt.subplots(figsize=(10, 6))
    
    bars = ax.bar(
        x=data["Dataset"],
        height=pd.to_numeric(data["TimeMicroseconds"]),
        color=color,
        alpha=0.7,
        width=0.6
    )

    ax.set_title(f"{algorithm_name} Algorithm Performance", pad=20)
    ax.set_xlabel("Dataset", labelpad=10)
    ax.set_ylabel("Execution Time (µs)", labelpad=10)
    
    for bar in bars:
        height = bar.get_height()
        ax.text(
            bar.get_x() + bar.get_width()/2.,
            height,
            f'{int(height)} µs',
            ha='center',
            va='bottom'
        )
    
    plt.tight_layout()
    plt.savefig(f"./output/{algorithm_name.lower().replace(' ', '')}_performance.png")
    plt.close()
        
def plot_combined(algorithms_data):

    fig, ax = plt.subplots(figsize=(12, 7))
    
    width = 0.25  # bar width

    x = range(len(algorithms_data[0]["data"]["Dataset"]))
    
    for i, algorithm in enumerate(algorithms_data):
        data = algorithm["data"]
        name = algorithm["name"]
        color = algorithm["color"]
        
        ax.bar(
            [pos + width*i for pos in x], 
            data["TimeMicroseconds"], 
            width=width, 
            label=name, 
            color=color, 
            alpha=0.8
        )
    
    ax.set_title("Knapsack Algorithms Performance Comparison", pad=20)
    ax.set_xlabel("Dataset", labelpad=10)
    ax.set_ylabel("Execution Time (µs)", labelpad=10)
    ax.set_xticks([pos + width for pos in x])
    ax.set_xticklabels(algorithms_data[0]["data"]["Dataset"])
    ax.legend()
    
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
        plot_algorithm(data, name, color)
        valid_data.append({"data": data, "name": name, "color": color})

    return valid_data

def main():

    algorithms_data = load_data()
    
    for alg in algorithms_data:
        alg["data"]["TimeMicroseconds"] = pd.to_numeric(alg["data"]["TimeMicroseconds"])

    plot_combined(algorithms_data)

if __name__ == "__main__":
    main()
