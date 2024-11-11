#Write A Shell Script To Find A Greater Number Out Of 3 Numbers.


echo "Enter three numbers:"

read -p "Enter the first number: " n1
read -p "Enter the second number: " n2
read -p "Enter the third number: " n3

# Using nested if-else to find the greatest number

if [[ $n1 -gt $n2 ]]; then
    if [ $n1 -gt $n3 ]; then
        echo "$n1 is the greatest number"
    else
        echo "$n3 is the greatest number"
    fi
else
    if [[ $n2 -gt $n3 ]]; then
        echo "$n2 is the greatest number"
    else
        echo "$n3 is the greatest number"
    fi
fi