#12.Write A Shell Script To Check Whether The Given String Is Palindrome Or Not.

#!/bin/bash

read -p "Enter a string: " str
echo ""

len=${#str}
reversed=""

for ((i=len-1; i>=0; i--)); do
  reversed+="${str:$i:1}"
done

if [[ "$str" == "$reversed" ]]; then
  echo "$str is a palindrome"
else
  echo "$str is not a palindrome"
fi