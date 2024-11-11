#Write A Shell Script Which Works Like A Calculator And Performs Below Operations: Addition, Subtract, Division And Multiplication.


while true; do
	echo -e "\nSlect Operation:"
	echo "1. Addition"
	echo "2. SUbtraction"
	echo "3. Multiplication"
	echo "4. Division"
	echo "5. Exit"

	read -p "Enter your choice: " choice

	case $choice in 
		1)
		read -p "Enter first number: " n1
		read -p "Enter second number " n2
		echo "Sum = $(($n1+$n2))";;

		2)
		read -p "Enter first number: " n1
		read -p "Enter second number " n2
		echo "Difference = $(($n1-n2))";;

		3)
		read -p "Enter first number: " n1
		read -p "Enter second number " n2
		echo "Product = $(($n1*$n2))";;

		4)
		read -p "Enter first number: " n1
		read -p "Enter second number " n2
		if [[ $n2 -eq 0 ]]; then
			echo "Error: Division by zero"
		else
			echo "Quotient = $(($n1/$n2))"
		fi;;

		5)exit 0;;

		*)
		echo "Inalid Choice!";;
	esac
done
