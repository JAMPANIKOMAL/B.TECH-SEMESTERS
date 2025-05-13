def knapsack_greedy(w, v, c):
    n = len(w)
    r = []
    
    for i in range(n):
        r.append((v[i] / w[i], w[i], v[i]))
    
    r.sort(reverse=True, key=lambda x: x[0])
    
    total = 0
    for i in r:
        if c >= i[1]:
            c -= i[1]
            total += i[2]
        else:
            total += i[2] * (c / i[1])
            break
    
    return total

w = [2, 3, 4, 5]
v = [3, 4, 5, 6]
c = 5

max_value = knapsack_greedy(w, v, c)
print(f"Maximum value: {max_value}")