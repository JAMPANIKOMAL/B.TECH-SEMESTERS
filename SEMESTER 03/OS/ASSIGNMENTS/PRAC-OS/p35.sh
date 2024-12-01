echo -n "Enter the first string: "
read string1
echo -n "Enter the second string: "
read string2
if [ "$string1" == "$string2" ]; then
echo "The strings are equal."
else
echo "The strings are not equal."
fi
