def knapsack(w, v, cap):
    n = len(w)
    dp = [[0] * (cap + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for c in range(1, cap + 1):
            if w[i - 1] <= c:
                dp[i][c] = max(v[i - 1] + dp[i - 1][c - w[i - 1]], dp[i - 1][c])
            else:
                dp[i][c] = dp[i - 1][c]
    
    return dp[n][cap]

weights = [2, 3, 4, 5]
values = [3, 4, 5, 6]
capacity = 5

max_val = knapsack(weights, values, capacity)
print(f"Maximum value in Knapsack: {max_val}")
