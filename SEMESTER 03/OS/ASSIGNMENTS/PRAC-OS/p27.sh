echo -n "Enter the base of the triangle: "
read base
echo -n "Enter the height of the triangle: "
read height
area=$(echo "scale=2; 0.5 * $base * $height" | bc)
echo "Area of the triangle: $area"