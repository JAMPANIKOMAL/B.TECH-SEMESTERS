#Write A Shell Script To Find The Value Of One Number Raised To The Power Of Another.


read -p "Enter the base number: " base
echo ""

read -p "Enter the exponent: " exponent
echo ""

result=1

for ((i=1; i<=exponent; i++)); do
  result=$((result * base))
done

echo "$base raised to the power of $exponent is $result"