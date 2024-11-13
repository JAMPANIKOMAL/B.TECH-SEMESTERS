#13.Write A Shell Script To Find First N Fibonacci Numbers Like: 0 1, 1, 2, 3, 5, 13.

#!/bin/bash

read -p "Enter the number of Fibonacci numbers to generate: " n

if [[ $n -le 0 ]]; then
  echo "Please enter a positive integer."
else
  a=0
  b=1
  echo -n "$a $b "

  for ((i=3; i<=n; i++)); do
    c=$((a + b))
    echo -n "$c "
    a=$b
    b=$c
  done
  echo
fi