def rod_cutting(p, n):
    if n == 0:
        return 0
    m = float('-inf')
    for i in range(n):
        m = max(m, p[i] + rod_cutting(p, n - i - 1))
    return m

p = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
n = int(input("Input the rod length: "))
print("Max price for rod of length", n, "is", rod_cutting(p, n))