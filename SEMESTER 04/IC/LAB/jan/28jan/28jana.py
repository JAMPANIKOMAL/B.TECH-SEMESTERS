# Columnar Transposition Encryption without padding  [Regular Columnar Transposition Encryption]

pt = input("\nEnter your plain text: ")
key = input("Enter your key: ")
ct = ""

pt = pt.lower()
key = key.lower()


#Removing spaces
fpt = ""
for i in pt:
    if i != " ":
        fpt = fpt + i

fk = ""
for i in key:
    if i != " ":
        fk = fk + i

cs = len(key)
matrix = []

# k = 0
# for j in fpt:
#     matrix.append([])
#     for i in range(cs):
#         matrix[k].append(j)
#     k += 1

# print(matrix, fpt, fk)

# cl = len(fk)
# rl = int(len(fpt) / len(fk))

# for ch in fpt:
#     for i in range(rl):
#         matrix.append([])
#         for j in range(cl):
#             matrix[i].append(ch)



# print(cl, rl, matrix)

if len(fpt) % len(fk) != 0:
    for i in range(len(fpt) % len(fk)):
        fpt = fpt + "-"

for i in fpt:
    
