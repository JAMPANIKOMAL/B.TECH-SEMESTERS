if __name__ == '__main__':
    n = int(input())
    arr = sorted(map(int, input().split()))

    a = float('-inf')
    
    for i in arr:
        if i > a:
            b = a
            a = i
    
    print(b)



'''
Input:
5
2 3 6 6 5

Output:
5
'''