# Practical 06
# Rod cutting problem
# Solving by Dynamic Programming method (Bottom-Up)

def cut_rod(prices, n):
    r = [0] * (n + 1)  # Initialize revenue array with 0s
    s = [0] * (n + 1)  # Initialize solution array with 0s (to store cut positions)

    for j in range(1, n + 1):  # Iterate through rod lengths from 1 to n
        q = float('-inf')  # Initialize max revenue for current length to negative infinity
        for i in range(1, j + 1):  # Iterate through possible cut positions
            if q < prices[i - 1] + r[j - i]:
                q = prices[i - 1] + r[j - i]  # Update max revenue if current cut yields better result
                s[j] = i  # Store the cut position

        r[j] = q  # Store the max revenue for the current rod length

    return r, s  # Return both revenue and solution arrays

def print_cut_rod_solution(prices, n):
    """
    Prints the optimal cuts for a rod of length n.

    Args:
        prices (list): A list of prices for rod pieces of different lengths.
        n (int): The length of the rod.
    """
    
    r, s = cut_rod(prices, n)  # Get revenue and solution arrays
    
    print("Optimal cuts:")
    while n > 0:
        print(s[n], end=" ")  # Print the cut position
        n = n - s[n]  # Update remaining rod length
    print()  # Print a newline for formatting

# Example usage
prices = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]  # Prices for rod pieces of lengths 1 to 10

n = int(input("Enter the length of rod: "))

max_revenue, _ = cut_rod(prices, n)  # Calculate max revenue
print("Max price of rod of length", n, "is", max_revenue[n])

print_cut_rod_solution(prices, n)  # Print the optimal cuts