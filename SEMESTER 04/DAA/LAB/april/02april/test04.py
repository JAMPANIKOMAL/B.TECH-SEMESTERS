import itertools

def substrings_decreasing_length(s):
    """Generates substrings of s in decreasing length order."""
    for i in range(len(s), 0, -1):
        for combo in itertools.combinations(s, i):
            yield "".join(combo)  # Use yield to create a generator

def longest_common_subsequence_optimized(s1, s2):
    """Finds the longest common subsequence by generating substrings in decreasing length."""
    
    ssl2 = set(substrings_decreasing_length(s2)) # Convert to set for faster lookup

    for sub in substrings_decreasing_length(s1):
        if sub in ssl2:
            return sub  # Found the longest common subsequence

    return ""  # No common subsequence found

# Get input strings
s1 = input("Input your first string: ")
s2 = input("Input your second string: ")

# Find and print the LCS
lcs = longest_common_subsequence_optimized(s1, s2)
print("Longest Common Subsequence:", lcs)