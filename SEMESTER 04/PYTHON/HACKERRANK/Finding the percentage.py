if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()

    li = student_marks[query_name]
    # avg =  sum(li)/len(li)
    # print("%.2f" % avg) 
    
    sum = 0.00
    
    for i in li:
        sum = sum + i
        
    a = sum/3
    print("%.2f" % a)

'''
Input:
3
Krishna 67 68 69
Arjun 70 98 63
Malika 52 56 60
Malika

Output:
56.00
'''