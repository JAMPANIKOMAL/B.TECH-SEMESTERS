# DES
# Using Bit padding

def decimaltobinary(t):
    mt = bin(t).replace("0b", "")
    return mt

def hextobinary(t):
    t.lower()
    mp = {'0': "0000", '1': "0001", '2': "0010", '3': "0011", '4': "0100", '5': "0101", '6': "0110", '7': "0111", '8': "1000", '9': "1001", 'a': "1010", 'b': "1011", 'c': "1100", 'd': "1101", 'e': "1110", 'f': "1111"} 
    mt = "" 
    for i in range(len(t)): 
        mt = mt + mp[t[i]]
    return mt

def stringtobianry(t):
    mt = ''.join(format(ord(i), '08b') for i in t)
    return mt

def binarytodecimal(t):
    return int(t, 2)

def binarytohex(t):
    decimal_val = int(t, 2)
    return hex(decimal_val).replace("0x", "").upper()

def binarytostring(t):
    mt = ""
    for i in range(0, len(t), 8):
        byte = t[i:i+8]
        mt += chr(int(byte, 2))
    return mt

def initialpermu(t):
    initial_perm = [58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7]

    mt = ""
    for i in range(64):
        mt += t[initial_perm[i] - 1]
    
    return mt

dhbs = int(input("Plain Text type, Enter 1 for decimal 2 for hex 3 for binary and 4 for string:"))
if dhbs in [1, 2, 3, 4]:
    pt = input("Enter your plain text: ")
else:
    print("Enter a valid choice!")
    exit()

opt = pt
if dhbs == 1:
    pt = decimaltobinary(int(pt))
elif dhbs == 2:
    pt = hextobinary(pt)
elif dhbs == 3:
    pt = pt
elif dhbs == 4:
    pt = stringtobianry(pt)

if len(pt) % 64 != 0:
    pt += "1"
    while len(pt) % 64 != 0:
        pt += "0"

print(f"Original Plain Text: {opt}")
print(f"Binary Plain Text: {pt}")


kt = int(input("Key type, Enter 1 for decimal 2 for hex 3 for binary and 4 for string: "))
if kt in [1, 2, 3, 4]:
    k = input("Enter your key: ")
else:
    print("Enter a valid choice!")
    exit()

if kt == 1:
    bk = decimaltobinary(int(k))
elif kt == 2:
    bk = hextobinary(k)
elif kt == 3:
    bk = k
elif kt == 4:
    bk = stringtobianry(k)

if len(bk) < 64:
    print(f"Warning: Key is too short ({len(bk)} bits). Padding with zeros.")
    bk = bk.zfill(64)
elif len(bk) > 64:
    print(f"Warning: Key is too long ({len(bk)} bits). Truncating to 64 bits.")
    bk = bk[:64]

print(f"Original key: {k}")
print(f"Processed key: {bk}")

ippt = initialpermu(pt)
print(f"Binary Plain Text after initial permutation: {ippt}")



