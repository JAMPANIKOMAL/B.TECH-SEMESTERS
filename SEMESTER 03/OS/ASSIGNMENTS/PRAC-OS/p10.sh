#Write A Shell Script In Which Will Accept A Number N And Display First N Prime Numbers As Output.

#!/bin/bash

read -p "Enter the number of prime numbers to display: " m
echo ""

num=2
count=1

while [[ $count -le $m ]]; do
  is_prime=1
  for ((i=2; i*i <= $num; i++)); do
    if [[ $((num % i)) -eq 0 ]]; then
      is_prime=0
      break
    fi
  done

  if [[ $is_prime -eq 1 ]]; then
    echo "$num"
    count=$((count + 1))
  fi

  num=$((num + 1))
done