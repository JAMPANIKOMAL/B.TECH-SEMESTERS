# Rail Fence Cipher Encryption
# Corrected error using Gemini

mt = str(input("Enter your message text: "))
depth = int(input("Enter your depth: "))
ct = ""

omt = mt
mt = mt.lower()
mt = mt.replace(" ", "")

rl = []

for i in range(depth):
    rl.append("") 

r = 0
direction = 1  # 1 for down, -1 for up

for i in mt:
    rl[r] += i
    r += direction

    if r == depth - 1 or r == 0:
        direction *= -1

for i in rl:
    ct += i

print("Your cipher text is:", ct)