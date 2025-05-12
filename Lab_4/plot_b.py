import matplotlib.pyplot as plt

# Define the range of n
n_values = range(1, 51)

# Compute values for O(n^2) and O(n^3)
o_n2 = [n**2 for n in n_values]
o_n3 = [n**3 for n in n_values]

# Plot the complexity functions
plt.plot(n_values, o_n2, label='O(n^2)', color='blue')
plt.plot(n_values, o_n3, label='O(n^3)', color='red')

# Add labels, title, and legend
plt.xlabel("n")
plt.ylabel("Value")
plt.title("Growth of Complexity Functions: O(n^2) and O(n^3)")
plt.legend()
plt.grid(True)

# Save the plot as an image file
plt.savefig("complexity_plot_graph2.png", dpi=300)  # High-resolution PNG

# Show the plot (optional)
plt.show()
