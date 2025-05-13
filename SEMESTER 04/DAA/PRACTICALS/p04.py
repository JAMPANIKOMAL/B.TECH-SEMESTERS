def merge_sort(lh, rh):
    na = []
    i = j = 0
    while i < len(lh) and j < len(rh):
        if lh[i] < rh[j]:
            na.append(lh[i])
            i += 1
        else:
            na.append(rh[j])
            j += 1
    na.extend(lh[i : ])
    na.extend(rh[j : ])
    return na

def divide(a):
    if len(a) <= 1:
        return a
    m = len(a) // 2
    lh = a[ : m]
    rh = a[m : ]
    lh = divide(lh)
    rh = divide(rh)
    return merge_sort(lh, rh)

a = [1, 9, 11, 7]
na = divide(a)
print(a, na)