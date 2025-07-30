from scipy import stats
import numpy as np # Already imported

print("--- SciPy Example ---")
# Sample data: hours studied vs. exam score
hours_studied = np.array([2, 3, 5, 7, 8])
exam_scores = np.array([65, 70, 78, 88, 92])

# Perform linear regression using SciPy's stats module
slope, intercept, r_value, p_value, std_err = stats.linregress(hours_studied, exam_scores)

print("Linear Regression Analysis (Hours Studied vs. Exam Score)")
print(f"Slope: {slope:.2f}")
print(f"Intercept: {intercept:.2f}")
print(f"R-squared value: {r_value**2:.2f}")

# Predict a score based on the regression model
predicted_score = slope * 6 + intercept
print(f"\nPredicted score for 6 hours of study: {predicted_score:.2f}")
print("-" * 20)
