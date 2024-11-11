#Write A Shell Script To Display The Multiplication Table Of The Given Number.


read -p "Enter a number: " num

echo -e "\nMultiplication table of $num:"

for i in {1..10}; do
  echo "$num x $i = $((num * i))"
done