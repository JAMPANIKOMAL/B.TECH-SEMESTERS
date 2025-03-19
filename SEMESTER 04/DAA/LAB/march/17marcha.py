# Practical 06
# Rod cutting problem
# Solving by Dynamic Programming method (Bottom-Up)
# Calculate time left not done

def cut_rod(prices, n):
    r = [0] * (n + 1)
    s = [0] * (n + 1)

    for i in range(1, n + 1):
        q = float('-inf')
        for j in range(1, i + 1):
            if q < prices[j - 1] + r[i - j]:
                q = prices[j - 1] + r[i - j]
                s[i] = j
        r[i] = q
    return r, s

def print_cut_rod_solution(prices, n):
    r, s = cut_rod(prices, n)
    print("Optimal cuts:")
    while n > 0:
        print(s[n], end=" ")
        n = n - s[n]
    print()

prices = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
n = int(input("Enter the length of rod: "))
max_revenue, _ = cut_rod(prices, n)
print("Max price of rod of length", n, "is", max_revenue[n])
print_cut_rod_solution(prices, n)