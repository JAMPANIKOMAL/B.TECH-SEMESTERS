s = "abc"
ct = ""
# n = n+chr(ord(s[0]) + 1)
# print(n)

ct = ct+chr((abs(ord(s[0]) - 0))%26)
print(ct)