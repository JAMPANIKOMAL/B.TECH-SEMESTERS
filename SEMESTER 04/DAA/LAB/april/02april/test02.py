import itertools

def substrings(s):
    ssl = []
    for i in range(len(s), 0, -1):  # Generate substrings in decreasing length order
        for j in itertools.combinations(s, i):
            ssl.append("".join(j))
    return ssl

s1 = input("Input your first string: ")
s2 = input("Input your second string: ")

ssl1 = substrings(s1)
ssl2 = set(substrings(s2)) # Convert to set for faster lookup

mss = []

for i in ssl1:
    if i in ssl2:
        mss.append(i)
        break # Stop after finding the first common subsequence

if mss:
    lcs = mss[0] # The first element will be the longest common subsequence
    print("Longest Common Subsequence:", lcs)
else:
    print("Longest Common Subsequence: ") # No common subsequence