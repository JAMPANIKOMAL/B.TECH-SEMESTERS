def rod_cutting(prices, n):
    dp = [0] * (n + 1)

    for i in range(1, n + 1):
        m = float('-inf') 
        for j in range(1, i + 1):
            m = max(m, p[j - 1] + dp[i - j])
        dp[i] = m 
    return dp[n]

p = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
n = int(input("Input the rod length: "))
print("Max price for rod of length", n, "is", rod_cutting(p, n))