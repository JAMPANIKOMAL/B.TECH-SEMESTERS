# Rod Cutting Using Divide and Conquer Method
# Only Prints Maximum Price
#Complete and working

def rod_ctting(p, n):
    if n == 0:
        return 0
    
    m = float('-inf')

    for i in range(n):
        m = max(m, p[i] + rod_ctting(p, n - i - 1))

    return m

prices = [1, 5, 8, 9, 10]
n = int(input("Inputer the Rod Length: "))
m = rod_ctting(prices, n)
print("Maximun price for rod of length", n, "is", m)