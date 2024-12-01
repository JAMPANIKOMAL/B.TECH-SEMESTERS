echo -n "Enter four numbers: "
read num1 num2 num3 num4
min=$num1
if [ $num2 -lt $min ]; then
min=$num2
fi
if [ $num3 -lt $min ]; then
min=$num3
fi
if [ $num4 -lt $min ]; then
min=$num4
fi
echo "The minimum value is: $min"