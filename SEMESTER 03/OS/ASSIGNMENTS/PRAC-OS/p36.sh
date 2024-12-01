echo -n "Enter the basic pay of the employee: "
read basic_pay
echo -n "Enter the percentage of HRA: "
read hra_percent
echo -n "Enter the percentage of DA: "
read da_percent
echo -n "Enter the percentage of TAX: "
read tax_percent
hra=$(echo "scale=2; $basic_pay * $hra_percent / 100" | bc)
da=$(echo "scale=2; $basic_pay * $da_percent / 100" | bc)
tax=$(echo "scale=2; $basic_pay * $tax_percent / 100" | bc)
gross_salary=$(echo "scale=2; $basic_pay + $hra + $da" | bc)
net_salary=$(echo "scale=2; $gross_salary - $tax" | bc)
echo "Gross Salary: $gross_salary"
echo "Tax Deducted: $tax"
echo "Net Salary: $net_salary"
