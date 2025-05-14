# DES
# Using Bit padding
# Some errors fixed using claude

def decimaltobinary(t):
    mt = bin(t).replace("0b", "")
    return mt

def hextobinary(t):
    t = t.lower()
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

def key64to56(k):
    keypairity_array = [57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4]
    nk = ""
    for i in range(56):
        if keypairity_array[i] - 1 < len(k):
            nk += k[keypairity_array[i] - 1]
        else:
            nk += "0"
    return nk

def expansion(t):
    exp_array = [32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1]
    nt = ""
    for i in range(48):
        nt += t[exp_array[i] - 1]
    return nt

def circular_shift(k, n):
    nk = ""
    for i in range(n):
        for j in range(1, len(k)):
            nk += k[j]
        nk += k[0]
        k = nk
        nk = ""
    return k

def key56to48(k):
    key_comp = [14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32]
    nk = ""
    for i in range(48):
        if key_comp[i] - 1 < len(k):
            nk += k[key_comp[i] - 1]
        else:
            nk += "0"
    return nk

def xor(a, b):
    c = ""
    for i in range(len(a)):
        if a[i] == b[i]:
            c += "0"
        else:
            c += "1"
    return c

def substitution(a):
    sbox = [[[14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7], [0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8], [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0], [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13]], [[15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10], [3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5], [0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15], [13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9]], [[10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8], [13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1], [13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7], [1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12]], [[7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15], [13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9], [10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4], [3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14]], [[2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9], [14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6], [4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14], [11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3]], [[12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11], [10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8], [9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6], [4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13]], [[4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1], [13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6], [1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2], [6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12]], [[13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7], [1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2], [7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8], [2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11]]]

    r = ""
    for i in range(0, 8):
        b = a[i * 6: i * 6 + 6]
        row = binarytodecimal(b[0] + b[5])
        col = binarytodecimal(b[1:5])
        val = sbox[i][row][col]
        r += bin(val)[2:].zfill(4)
    return r

def permutation(a):
    per = [16,  7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2,  8, 24, 14, 32, 27,  3,  9, 19, 13, 30,  6, 22, 11,  4, 25]
    na = ""
    for i in range(32):
        na += a[per[i] - 1]
    return na

def final_permutation(a):
    final_perm = [40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25]
    na = ""
    for i in range(64):
        na += a[final_perm[i] - 1]
    return na

def encryption(pt, k):
    pt = initialpermu(pt)
    # print(f"Binary Plain Text after initial permutation: {pt}")

    lpt = pt[0:32]
    rpt = pt[32:]

    # Store original key
    orig_k = k

    for i in range(0, 16):
        erpt = expansion(rpt)
        # print(f"48 Bit rpt: {erpt}")

        if i == 0:  # Only convert from 64 to 56 in first round
            k = key64to56(k)
        # print(f"56 Bit key: {k}")

        lk = k[0:28]
        rk = k[28:]

        shift_table = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]

        slk = circular_shift(lk, shift_table[i])
        srk = circular_shift(rk, shift_table[i])

        k = slk + srk
        nk = key56to48(k)

        xrpt = xor(erpt, nk)
        sxrpt = substitution(xrpt)
        psxrpt = permutation(sxrpt)

        temp = rpt
        rpt = xor(lpt, psxrpt)
        lpt = temp

    c = rpt + lpt
    ct = final_permutation(c)
    return ct
    
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
    # print(f"Warning: Key is too short ({len(bk)} bits). Padding with zeros.")
    bk = bk.zfill(64)
elif len(bk) > 64:
    # print(f"Warning: Key is too long ({len(bk)} bits). Truncating to 64 bits.")
    bk = bk[:64]

print(f"Original key: {k}")
# print(f"Processed key: {bk}")

ct = encryption(pt, bk)

oct = ""
if dhbs == 1:
    oct = binarytodecimal(int(ct))
elif dhbs == 2:
    oct = binarytohex(ct)
elif dhbs == 3:
    oct = ct
elif dhbs == 4:
    oct = binarytostring(ct)

print("Cipher text: ", oct)