def string_copy(a):
    return a

def string_reverse(a):
    b = ""
    i = len(a) - 1
    while i >= 0:
        b += a[i]
        i -= 1
    return b

def string_equality(a, b):
    if len(a) != len(b):
        return 0
    else:
        for i , j in a, b:
            if i != j:
                return 0
        
a = input("Input your string: ")

while True:
    print("Select from the following:")
    print("1. String Copy")
    print("2. Sting Reverse")
    print("3. String compare")
    print("4. Exit")
    i = int(input("Input your option: "))

    if i == 1:
        b = string_copy(a)
        print(a, b, "\n")

    elif i == 2:
        b = string_reverse(a)
        print(a, b, "\n")

    elif i == 3:
        b = input("Input the string to be compared: ")
        if string_equality(a, b):
            print("Equal", "\n")
        else:
            print("Not Equal", "\n")

    else:
        break