def activity_selection(st, ft):
    n = len(st)
    a = []
    for i in range(n):
        a.append(('a' + str(i + 1), st[i], ft[i]))
    a.sort(key = lambda x : x[2])
    sel = []
    lf = 0
    for n, s, f in a:
        if s >= lf:
            sel.append(n)
            lf = f
    return sel

start = [1, 3, 0, 5, 8, 5]
finish = [2, 4, 6, 7, 9, 9]
sa = activity_selection(start, finish)
print("Selected activities:", sa)