# 24.Write A Shell Program To Conversion Of Celsius To Fahrenheit.

echo ""
read -p "Enter temparature in celcius: " t

echo "Temperature in Fahrenheit = $(echo "scale=2; ($t * 9/5) + 32" | bc)"