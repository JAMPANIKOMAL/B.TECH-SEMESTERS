if __name__ == '__main__':
    li = []
    for i in range(int(input())):
        name = input()
        score = float(input())
        li.append([])
        li[i].append(name)
        li[i].append(score)
        
    
    sl1 = sorted(li, key=lambda l:l[1], reverse = True)
    sl2 = sorted(li, key=lambda l:l[0])
    
    a = float('inf')
    
    for i in sl1:
        if i[1] < a:
            b = a
            a = i[1]
            
    #print(sl1, a, b)
            
    for i in sl2:
        if i[1] == b:
            print(i[0])



'''
Input: 
5
Harry
37.21
Berry
37.21
Tina
37.2
Akriti
41
Harsh
39

Output:
Berry
Harry
'''