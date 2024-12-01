#Write A Shell Script To Check Whether A Given Number Is Palindrome Or Not.


read -p "Enter a number: " num
# echo ""

original_num=$num
reverse=0

while [[ $num -gt 0 ]]; do
  remainder=$((num % 10))
  reverse=$((reverse * 10 + remainder))
  num=$((num / 10))
done

if [[ $original_num -eq $reverse ]]; then
  echo "$original_num is a palindrome number"
else
  echo "$original_num is not a palindrome number"
fi