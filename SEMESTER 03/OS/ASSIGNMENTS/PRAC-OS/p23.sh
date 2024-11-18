# 23.Write A Shell Program To Area And Circumference Of A Circle.

echo ""
read -p "Enter radius of circle: " r

#echo "Circumference = $((2 * 3.14 * $r))"

echo "Circumference = $(echo "scale=2; 2*3.14*$r" | bc)"
echo "Area = $(echo "scale=2; 3.14*$r*$r" | bc)"