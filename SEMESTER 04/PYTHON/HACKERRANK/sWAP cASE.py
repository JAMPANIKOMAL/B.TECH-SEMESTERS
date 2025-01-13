#pyp3

def swap_case(s):
    us = s.upper()
    ls = s.lower()
    
    fs = ""
    
    for i in range(len(s)):
        if s[i] == us[i]:
            fs = fs + ls[i]
            
        elif s[i] == ls[i]:
            fs = fs + us[i] 
  
    # fs = s.swapcase()
  
    return fs

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)

'''
Input:
HackerRank.com presents "Pythonist 2".

Output:
hACKERrANK.COM PRESENTS "pYTHONIST 2".
'''