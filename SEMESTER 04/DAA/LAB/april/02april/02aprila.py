# Longest Common Subsequence 
# Not feasible run-time is very high

import itertools

def substrings(s):
  ssl = []
  for i in range(len(s), 0, -1):
    for i in itertools.combinations(s, i):
      ssl.append("".join(i))
  return ssl

s1 = input("Input your first string: ")
s2 = input("Input your second string: ")

ssl1 = substrings(s1)
ssl2 = substrings(s2)

mss = []

for i in ssl1:
  if i in ssl2:
    mss.append(i)

lcs = max(mss, key = len)

print("Longest Common Subsequence:", lcs)