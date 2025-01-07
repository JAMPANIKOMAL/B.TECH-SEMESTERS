#Decoding
ct = str(input("Enter your cipher text: "))

mt = ""

for key in range(26):
    for x in ct:
        mt = mt+chr(abs(ord(x) - (key - 1)%26))
    print("Message text if key = ", key, ": ", mt)
    mt = ""