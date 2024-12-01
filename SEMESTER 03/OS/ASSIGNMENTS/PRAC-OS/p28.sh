echo -n "Enter a number: "
read number
square=$(echo "$number^2" | bc)
cube=$(echo "$number^3" | bc)
echo "Square of $number: $square"
echo "Cube of $number: $cube"