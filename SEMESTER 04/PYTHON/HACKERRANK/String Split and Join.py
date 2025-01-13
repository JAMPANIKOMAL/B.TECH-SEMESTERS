# pyp3y 3



def split_and_join(line):
    line = line.split(" ")
    line = "-".join(line)
    return line

if __name__ == '__main__':
    line = input()
    result = split_and_join(line)
    print(result)


'''
Input:
this is a string

Output:
this-is-a-string
'''