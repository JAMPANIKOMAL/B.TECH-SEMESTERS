# Practical 05
# Rod cutting problem
# Solving by divide and conquer method

def cutrod(prices, n):
    if n == 0:
        return 0

    q = float('-inf')  

    for i in range(1, n + 1):
        q = max(q, prices[i - 1] + cutrod(prices, n - i))

    return q    

prices = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]

n = int(input("Enter the length of rod: "))

print("Max price of rod of length", n, "is", cutrod(prices, n))