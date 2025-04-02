# Rail Fence Cipher Dcryption
# INcomplete

ct = str(input("Enter your cipher text: "))
depth = int(input("Enter your depth: "))
mt = ""

oct = ct
ct = ct.lower()
ct = ct.replace(" ", "")

rl = []

for i in range(depth):
    rl.append("") 

r = 0
direction = 1  # 1 for down, -1 for up

for i in ct:
    rl[r] += i
    r += direction

    if r == depth - 1 or r == 0:
        direction *= -1

for i in rl:
    mt += i

print("Your messagm text is:", ct)