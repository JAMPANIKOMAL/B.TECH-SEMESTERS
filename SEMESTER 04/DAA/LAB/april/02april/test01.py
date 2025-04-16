import itertools

def string_combinations(x):
  """Generates all combinations of characters in a string."""
  result = []
  for i in range(len(x), 0, -1):
    for combo in itertools.combinations(x, i):
      result.append("".join(combo))
  return result

x = 'abc'
print(string_combinations(x))