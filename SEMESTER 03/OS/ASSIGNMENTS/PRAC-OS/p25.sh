# 25.Write A Shell Program To Swap Two Values.

echo ""
read -p "Enter a: " a
read -p "Enter b: " b

c=$a 
a=$b
b=$c 

echo -e "\na = $a"
echo "b = $b"