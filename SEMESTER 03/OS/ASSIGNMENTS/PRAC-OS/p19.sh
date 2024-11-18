#19.Write A Shell Script Which Checks Whether A Given User Is Valid Or Not.

#!/bin/bash

read -p "Enter username to check: " username

if id -u "$username" &> /dev/null; then
  echo "$username is a valid user."
else
  echo "$username is not a valid user."
fi