# Playfair Cipher

pt = input("\nEnter your plain text: ")
key = input("Enter your key: ")
ct = ""

pt = pt.lower()
key = key.lower()

alphabetstring = "abcdefghijklmnopqrstuvwxyz"
uk = ""

for i in key:
    if i not in uk:
        uk = uk + i

for i in alphabetstring:
    if i not in uk:
        uk = uk + i

for i in range(len(uk)):
    if uk[i] == "j":
        uk = uk[:i] + "i" + uk[i+1 :]

fk = ""

for i in uk:
    if i not in fk and i != " ":
        fk = fk + i

upt = ""

for i in pt:
    if i != " ":
        upt = upt + i

if len(upt) % 2!= 0:
    upt = upt + "x"

for i in range(0, len(upt), 2):
    if upt[i] == upt[i + 1]:
        upt = upt[:i + 1] + "x" + upt[i + 1:]

if len(upt) % 2!= 0:
    upt = upt + "x"

if upt[len(upt) - 2] == upt [len(upt) -1]:
    upt = upt[:(len(upt) - 2)]
 
matrix = [[], [], [], [], []]

for i in fk[0:5]:
    matrix[0].append(i)

for i in fk[5:10]:
    matrix[1].append(i)

for i in fk[10:15]:
    matrix[2].append(i)

for i in fk[15:20]:
    matrix[3].append(i)

for i in fk[20:25]:
    matrix[4].append(i)

for i in range(0, len(upt), 2):
    ith = ipth = ""
    for j in range(5):
        if upt[i] in matrix[j]:
            ith = ith + str(j)
            ith = ith + str(matrix[j].index(upt[i]))

        if upt[i + 1] in matrix[j]:
            ipth = ipth + str(j)
            ipth = ipth + str(matrix[j].index(upt[i+1]))
  
    #Same row
    if ith[0] == ipth[0]:
        if int(ith[1]) <= 3:
            ct = ct + matrix[int(ith[0])][int(ith[1]) + 1]
        else:
            ct = ct + matrix[int(ith[0])][0]
    
    if ith[0] == ipth[0]:
        if int(ipth[1]) <= 3:
            ct = ct + matrix[int(ipth[0])][int(ipth[1]) + 1]
        else:
            ct = ct + matrix[int(ipth[0])][0]
    
    #Same column
    if ith[1] == ipth[1]:
        if int(ith[0]) <= 3:
            ct = ct + matrix[int(ith[0]) + 1][int(ith[1])]
        else:
            ct = ct + matrix[0][int(ith[1])]
    
    if ith[1] == ipth[1]:
        if int(ipth[0]) <= 3:
            ct = ct + matrix[int(ipth[0]) + 1][int(ipth[1])]
        else:
            ct = ct + matrix[0][int(ipth[1])]

    #Different row different column
    if ith[0] != ipth[0] and ith[1] != ipth[1]:
        ct = ct + matrix[int(ith[0])][int(ipth[1])]
        ct = ct + matrix[int(ipth[0])][int(ith[1])]

print("Your Cipher text is:", ct,"\n")