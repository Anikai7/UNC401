import matplotlib.pyplot as plt
import math

# Define the range of n
n_values = range(1, 101)

# Precompute values for each complexity function
complexities = {
    "O(1)": [1 for _ in n_values],
    "O(log n)": [math.log(n) for n in n_values],
    "O(√n)": [math.sqrt(n) for n in n_values],
    "O(n)": [n for n in n_values],
    "O(n log n)": [n * math.log(n) for n in n_values]
}

# Plot each complexity function
for label, values in complexities.items():
    plt.plot(n_values, values, label=label)

# Add labels, title, and legend
plt.xlabel("n")
plt.ylabel("Value")
plt.title("Growth of Complexity Functions")
plt.legend()
plt.grid(True)

# Save the plot as an image file
plt.savefig("complexity_plot.png")  # Saves as a PNG file

# Optional: Save in other formats (e.g., PDF, JPG)
# plt.savefig("complexity_plot.pdf")
