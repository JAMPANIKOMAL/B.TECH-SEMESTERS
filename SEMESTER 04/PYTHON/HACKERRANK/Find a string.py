def count_substring(string, sub_string):
    # ns = string
    # count = 0
    # while True:
    #     if sub_string in ns:
    #         count += 1
    #         ns = ns.replace(sub_string, "")
            
    #     else:
    #         break
        
    # count = string.count(sub_string)
  
    ls = len(string)
    lenss = len(sub_string)
    count = 0

    for i in range((ls - lenss) + 1):
        if sub_string == string[i : (i + lenss)]:
            count = count + 1  
    return count      

if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)



'''
Input:
ABCDCDC 
CDC

Output:
2
'''
