#Write A Shell Script To Find Sum & Average Of N Numbers.


read -p "Enter the number of numbers: " n
echo ""

sum=0
for ((i=1; i<=n; i++)); do
  read -p "Enter number $i: " num
  sum=$((sum + num))
done

avg=$((sum / n))

echo -e "\nSum of the numbers: $sum"
echo "Average of the numbers: $avg"