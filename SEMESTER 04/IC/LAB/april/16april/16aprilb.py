# AES ENCRYPTION
# With geminis help

def decimaltobinary(t):  # Decimal to binary
    return bin(t).replace("0b", "")

def hextobinary(t):  # Hex to binary
    t = t.lower()
    hex_to_bin = {'0': "0000", '1': "0001", '2': "0010", '3': "0011",
                  '4': "0100", '5': "0101", '6': "0110", '7': "0111",
                  '8': "1000", '9': "1001", 'a': "1010", 'b': "1011",
                  'c': "1100", 'd': "1101", 'e': "1110", 'f': "1111"}
    return ''.join(hex_to_bin[char] for char in t)

def stringtobianry(t):  # String to binary
    return ''.join(format(ord(char), '08b') for char in t)

def binarytodecimal(t):  # Binary to decimal
    return int(t, 2)

def binarytohex(t):  # Binary to hex
    return hex(int(t, 2)).replace("0x", "").upper()

def binarytostring(t):  # Binary to string
    return ''.join(chr(int(t[i:i + 8], 2)) for i in range(0, len(t), 8))

def xor(a, b):
    c = ""
    for i in range(len(a)):
        if a[i] == b[i]:
            c += "0"
        else:
            c += "1"
    return c



def tostate(pt):  # Converts binary plaintext to a 4x4 state matrix (column-major).
    hpt = binarytohex(pt)
    state = [[], [], [], []]
    byte_index = 0
    for i in range(4):
        for j in range(4):
            state[j].append(hpt[byte_index * 2: byte_index * 2 + 2])
            byte_index += 1
    return state


def aes(pt, bk, ks):
    state = tostate(pt)


if __name__ == "__main__":
    print("AES Encryption")

    # Get plaintext input
    dhbs = int(input("Plain Text type, Enter 1 for decimal 2 for hex 3 for binary and 4 for string: "))
    if dhbs not in [1, 2, 3, 4]:
        print("Enter a valid choice!")
        exit()

    pt = input("Enter your plain text: ")
    opt = pt  # Store original plaintext for display

    # Convert plaintext to binary
    if dhbs == 1:
        pt = decimaltobinary(int(pt))
    elif dhbs == 2:
        pt = hextobinary(pt)
    elif dhbs == 4:
        pt = stringtobianry(pt)

    # PKCS#7 Padding for plaintext
    block_size_bytes = 16  # AES block size in bytes (128 bits / 8 bits/byte)
    padding_needed = block_size_bytes - (len(pt) // 8) % block_size_bytes  # Calculate padding in bytes
    if padding_needed != block_size_bytes:
        padding_value = bytes([padding_needed]) * padding_needed
        pt += ''.join(format(x, '08b') for x in padding_value)

    print(f"Original Plain Text: {opt}")
    print(f"Binary Plain Text: {pt}")

    # Get key input
    ks = int(input("Input key size (128, 192, 256): "))
    if ks not in [128, 192, 256]:
        print("Invalid key size. Choose 128, 192, or 256.")
        exit()

    kt = int(input("Key type, Enter 1 for decimal 2 for hex 3 for binary and 4 for string: "))
    if kt not in [1, 2, 3, 4]:
        print("Enter a valid choice!")
        exit()

    key_length_bytes = ks // 8  # Key length in bytes
    k = input(f"Enter your {ks}-bit key ({key_length_bytes} bytes): ")

    # Convert key to binary and enforce key length
    if kt == 1:
        bk = decimaltobinary(int(k))
    elif kt == 2:
        bk = hextobinary(k)
    elif kt == 4:
        bk = stringtobianry(k)
    else:
        bk = k  # Key is already binary

    # Enforce key length (rejecting invalid lengths)
    if len(bk) != ks:
        print(f"Error: Key must be exactly {ks} bits.")
        exit()

    print(f"Original key: {k}")

    ct = aes(pt, bk, ks)  # Perform AES encryption (placeholder)
    print("Cipher Text:", ct)