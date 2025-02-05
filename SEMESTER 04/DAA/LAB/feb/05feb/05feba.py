# Merge Sort

import random 

def mergesort(a1, l1, r1):
    if l1 < r1:
        m1 = (l1 + r1) // 2

        mergesort(a1, l1, m1)
        mergesort(a1, m1 + 1, r1)

        merge(a1, l1, m1, r1)

def merge(a2, l2, m2, r2):
    n1 = m2 - l2 + 1   # number of elements in left subarray
    n2 = r2 - m2       # number of elements in right subarray

    la1 = [0] * n1
    ra1 = [0] * n2

    # copying elements to subarrays
    for i in range(n1):
        la1[i] = a2[l2 + i]
    
    for i in range(n2):
        ra1[i] = a2[m2 + 1 + i]

    i = 0
    j = 0
    k = l2

    # sorting and replacing in original array
    while i < n1 and j < n2:
        if la1[i] < ra1[j]:
            a2[k] = la1[i] 
            k += 1
            i += 1

        else:
            a2[k] = ra1[j]
            k += 1
            j += 1

    while i < n1:
        a2[k] = la1[i]
        k += 1
        i += 1

    while j < n2:
        a2[k] = ra1[j]
        k += 1
        j += 1

if __name__ == "__main__":
    a1 = []
    for i in range(5):
        temp = random.randint(0, 100)
        a1.append(temp)

    print("Given array:", a1)

    mergesort(a1, 0, len(a1) - 1)

    print("Sorted array:", a1)

