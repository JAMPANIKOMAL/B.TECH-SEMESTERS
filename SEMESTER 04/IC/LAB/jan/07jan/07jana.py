# Ceaser Cipher

# Encoding
mt = str(input("Enter your message text: "))
key = int(input("Enter your key: "))

ct = ""

for x in mt:
    ct = ct+chr((ord(x) + key))

print("Your cipher text is: ", ct)

