import matplotlib.pyplot as plt
import numpy as np # Already imported, but good practice for standalone snippets

# Data for plotting
x_values = np.arange(1, 6)
y_values = x_values ** 2

print("--- Matplotlib Example ---")
print("Generating a plot of y = x^2...")

# Create a plot
plt.figure(figsize=(8, 5))
plt.plot(x_values, y_values, marker='o', linestyle='--', color='b', label='y = x^2')
plt.xlabel("X Value")
plt.ylabel("Y Value (x^2)")
plt.title("Simple Line Plot")
plt.grid(True)
plt.legend()
plt.savefig("simple_plot.png")
print("Plot saved as simple_plot.png")
print("-" * 20 + "\n")
