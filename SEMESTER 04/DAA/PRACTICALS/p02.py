def binary_search(a, t):
    l = 0
    r = len(a) - 1
    
    while l <= r:
        m = (l + r) // 2
        if a[m] == t:
            return m
        elif a[m] < t:
            l = m + 1
        else:
            r = m - 1
    return -1

a = [1, 2, 3, 4, 5]
t = 7

r = binary_search(a, t)
if r != -1:
    print(1, "found at index", r)
else:
    print(t, "is not in array")