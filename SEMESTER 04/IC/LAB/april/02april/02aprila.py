# Rail Fence Cipher of depth 2

mt = str(input("Enter your message text: "))

omt = mt

mt = mt.lower()
mt = mt.replace(" ", "")

ct = ""

r1 = r2 = ""

for i in range(len(mt)):
    if i % 2 == 0:
        r1 += mt[i]
    else:
        r2 += mt[i]

ct = r1 + r2

print("Your cipher text is:", ct)