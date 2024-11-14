#15.Write A Shell Script To Read N Numbers As Command Arguments And Sort Them In Descending Order.

#Doubt

#!/bin/bash

if [ $# -eq 0 ]; then
  echo "Please provide at least one number as an argument."
  exit 1
fi

numbers=("$@")
length=${#numbers[@]}

for ((i=0; i<length-1; i++)); do
  for ((j=0; j<length-i-1; j++)); do
    if [[ ${numbers[j]} -lt ${numbers[j+1]} ]]; then
      temp=${numbers[j]}
      numbers[j]=${numbers[j+1]}
      numbers[j+1]=$temp
    fi
  done
done

echo "Numbers in descending order:"
for num in "${numbers[@]}"; do
  echo "$num"
done