echo "Select vehicle for rental charge:"
echo "1. Car"
echo "2. Van"
echo "3. Jeep"
echo "4. Bus"
echo -n "Enter the number corresponding to your choice: "
read vehicle_choice
case $vehicle_choice in
1)
rent=20
;;
2)
rent=30
;;
3)
rent=40
;;
4)
rent=50
;;
*)
echo "Invalid choice"
exit 1
;;
esac
echo -n "Enter the number of kilometers to travel: "
read kilometers
total_rent=$(echo "scale=2; $rent * $kilometers" | bc)
echo "The total rental charge for $kilometers kilometers is: $total_rent"