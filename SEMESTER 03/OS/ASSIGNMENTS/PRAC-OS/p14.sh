: '14.Write A Shell Script Which Will Print The Following Menu And Execute The Given Task?
A) Display Calendar Of Current Month
B) Display Today’s Date And Time
C) Display Usernames That Are Currently Logged In The System 
D) Display Your Name At Given X, Y Position
E) Display Your Terminal Number '


while true; do
	echo -e "\nSlect Operation:"
	echo "1. Display Calendar Of Current Month"
	echo "2. Display Today’s Date And Time"
	echo "3. Display Usernames That Are Currently Logged In The System"
	echo "4. Display Your Name At Given X, Y Position"
	echo "5. Display Your Terminal Number"
    echo -e "6. Exit\n"

	read -p "Enter your choice: " choice
    echo ""

	case $choice in 
		1)
		cal;;

		2)
		date;;

		3)
		who;;

		4)
		read -p "Enter x coordinate: " x
		read -p "Enter y coordinate " y
		tput cup $y $x
        whoami;;

        5)
        echo "Your terminal number is: $$";;

		6)exit 0;;

		*)
		echo "Invalid Choice!";;
	esac
done

