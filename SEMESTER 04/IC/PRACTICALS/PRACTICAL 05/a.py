pt = input("\nEnter your plain text: ")
key = input("Enter your key (no duplicates): ")

pt = pt.replace(" ", "").lower()
key = key.lower()

# Padding plaintext if needed
while len(pt) % len(key) != 0:
    pt += "x"

# Create the matrix
cols = len(key)
rows = len(pt) // cols
matrix = []

for r in range(rows):
    row = []
    for c in range(cols):
        row.append(pt[r * cols + c])
    matrix.append(row)

# Sort the key and track column order
key_order = sorted(list(enumerate(key)), key=lambda x: x[1])
ct = ""

for index, _ in key_order:
    for row in matrix:
        ct += row[index]

print("\nCipher Text:", ct)