mt = input("Enter your message text: ")
depth = int(input("Enter your depth (number of rails): "))
ct = ""

mt = mt.replace(" ", "").lower()
rails = ['' for _ in range(depth)]
row = 0
direction = 1

for ch in mt:
    rails[row] += ch
    row += direction
    if row == 0 or row == depth - 1:
        direction *= -1

for rail in rails:
    ct += rail

print("Your cipher text is:", ct)