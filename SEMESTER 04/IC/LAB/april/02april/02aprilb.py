# Rail Fence Cipher Encryption
# Hass error

mt = str(input("Enter your message text: "))
depth = int(input("Enter your depth: "))
ct = ""

omt = mt
mt = mt.lower()
mt = mt.replace(" ", "")

rl = []

for i in range(depth):
    rl.append("") 

for i in range(len(mt)):
    for j in range(1, depth):
        if i % j == 0:
            rl[j] += mt[i]

for i in rl:
    ct += i

print("Your cipher text is:", ct)