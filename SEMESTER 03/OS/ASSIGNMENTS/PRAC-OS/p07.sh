#Write A Shell Script To Find Factorial Of Given Number N.


read -p "Enter a non-negative integer: " n
echo ""

if [[ $n -lt 0 ]]; then
  echo "Factorial is not defined for negative numbers."
elif [[ $n -eq 0 ]]; then
  echo "Factorial of 0 is 1"
else
  factorial=1
  for ((i=1; i<=n; i++)); do
    factorial=$((factorial * i))
  done
  echo "Factorial of $n is $factorial"
fi