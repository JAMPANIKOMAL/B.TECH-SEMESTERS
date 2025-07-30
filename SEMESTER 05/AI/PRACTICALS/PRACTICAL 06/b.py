import pandas as pd

# Create a Pandas DataFrame
data = {'Name': ['Alice', 'Bob', 'Charlie', 'David', 'Eve'],
        'Age': [22, 25, 29, 35, 41],
        'City': ['New York', 'Los Angeles', 'Chicago', 'Houston', 'Phoenix']}
df = pd.DataFrame(data)

print("--- Pandas Example ---")
print("User Data DataFrame:")
print(df)

# Get descriptive statistics
print("\nDescriptive Statistics for Age:")
print(df['Age'].describe())
print("-" * 20 + "\n")