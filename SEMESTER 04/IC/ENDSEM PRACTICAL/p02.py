# Caeser Cipher
# Deryption
# Brute Forcing i.e., printing all possible Plain Text

ct = input("Input your Cipher text: ")
print("Cipher Text:", ct)


for key in range(26):
    pt = ""
    for i in ct:
        if i == " ":
            pt += " "
        else:
            pt += chr(ord(i) - (key % 26))
    print("Plain Text for key = :", key, "is:", pt)