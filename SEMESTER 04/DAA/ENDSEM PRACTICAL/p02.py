# Rod Cutting Using Divide and Conquer Method
# Trying to Print The cuts alnog with price also
# Not Complete

def rod_ctting(prices, n):
    if n == 0:
        return 0
    
    ca = []
    
    m = float('-inf')

    for i in range(n):
        m = max(m, p[i] + rod_ctting(p, n - i - 1))


    return m

p = [1, 5, 8, 9, 10]
n = int(input("Inputer the Rod Length: "))
m = rod_ctting(p, n)
print("Maximun price for rod of length", n, "is", m)