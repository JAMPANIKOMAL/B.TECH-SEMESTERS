#Use pyp3

if __name__ == '__main__':
    n = int(input())
    integer_list = map(int, input().split())
    
    t = tuple(integer_list)
    print(hash(t))


'''
Input:
2
1 2

Output:
3713081631934410656
'''