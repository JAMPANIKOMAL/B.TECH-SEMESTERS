current_hour=$(date +"%H")
if [ $current_hour -ge 5 ] && [ $current_hour -lt 12 ]; then
echo "Good Morning!"
elif [ $current_hour -ge 12 ] && [ $current_hour -lt 17 ]; then
echo "Good Afternoon!"
elif [ $current_hour -ge 17 ] && [ $current_hour -lt 21 ]; then
echo "Good Evening!"
else
echo "Good Night!"
fi
