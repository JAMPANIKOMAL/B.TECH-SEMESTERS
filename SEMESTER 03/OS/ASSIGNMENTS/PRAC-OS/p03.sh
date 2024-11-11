#Write A Shell Script To Find The Largest Among The 3 Given Numbers Using Switch Case


echo "Enter three numbers:"

read -p "Enter the first number: " n1
read -p "Enter the second number: " n2
read -p "Enter the third number: " n3

case $((n1 > n2 && n1 > n3)) in
  1)
    echo "The largest number is: $n1"
    ;;
  0)
    case $((n2 > n3)) in
      1)
        echo "The largest number is: $n2"
        ;;
      0)
        echo "The largest number is: $n3"
        ;;
    esac
    ;;
esac