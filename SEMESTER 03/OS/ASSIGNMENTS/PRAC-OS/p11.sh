#11.Write A Shell Script To Print The Pyramid Structure For The Given Number.

#!/bin/bash

read -p "Enter the number of rows: " rows
echo ""

for ((i=1; i<=rows; i++)); do
  for ((j=1; j<=rows-i; j++)); do
    echo -n " "
  done
  for ((k=1; k<=2*i-1; k++)); do
    echo -n "*"
  done
  echo
done