# Caeser Cipher
# Encryption

pt = input("Input your Plain text: ")
key = int(input("Input your key: "))

ct = ""

for i in pt:
    if i == " ":
        ct += " "
    else:
        ct += chr(ord(i) + (key % 26))

print("\nPlain Text:", pt)
print("Key:", key)
print("Cipher Text:", ct)