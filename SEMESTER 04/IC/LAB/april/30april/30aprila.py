# Columnar Cipher

pt = input("Input your plaintext: ")
key = input("Input your key: ")
ct = ""

opt = pt

nc = len(key)

if len(pt) % nc != 0:
    for i in range(nc - len(pt) % nc):
        pt += "-"

pt = pt.replace(" ", "-")

# print(pt, len(pt), nc)

rows = int(len(pt) / len(key))
cols = nc
another_2d_list = [[0 for _ in range(cols)] for _ in range(rows)]
# print(another_2d_list)  


