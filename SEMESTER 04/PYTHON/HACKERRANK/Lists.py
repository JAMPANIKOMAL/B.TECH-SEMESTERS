if __name__ == '__main__':
    N = int(input())
    
    arr = []
    tarr = []
    
    for i in range(N):
        x = input()
        tarr = x.split()
        
        if tarr[0] == "insert":
            arr.insert(int(tarr[1]), int(tarr[2]))
            
        elif tarr[0] == "append":
            arr.append(int(tarr[1]))
            
        elif tarr[0] == "remove":
            arr.remove(int(tarr[1]))
            
        elif tarr[0] == "print":
            print(arr)
            
        elif tarr[0] == "sort":
            arr.sort()
            
        elif tarr[0] == "reverse":
            arr.reverse()
        
        elif tarr[0] == "pop":
            arr.pop()


'''
Input:
12
insert 0 5
insert 1 10
insert 0 6
print
remove 6
append 9
append 1
sort
print
pop
reverse
print

Output:
[6, 5, 10]
[1, 5, 9, 10]
[9, 5, 1]
'''