# Public keys
P = 23  # Prime number
G = 9   # Primitive root

print("Public Key (P):", P)
print("Primitive Root (G):", G)

# Private keys
a = 4  # Alice
b = 3  # Bob

print("Alice's Private Key:", a)
print("Bob's Private Key:  ", b)

# Public values
A = pow(G, a, P)  # Alice sends this
B = pow(G, b, P)  # Bob sends this

# Shared secret calculation
secret_Alice = pow(B, a, P)
secret_Bob   = pow(A, b, P)

print("Shared Secret (Alice):", secret_Alice)
print("Shared Secret (Bob):  ", secret_Bob)