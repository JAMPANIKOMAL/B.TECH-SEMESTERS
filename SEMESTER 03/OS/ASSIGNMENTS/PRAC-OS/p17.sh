#17.Write A Shell Script To Display The Date, Time And A Welcome Message (Like Good Morning Etc.). The Time Should Be Displayed With A.M. Or P.M. And Not In 24 Hours Notation.

#!/bin/bash

current_time=$(date +"%H:%M:%S")

if [[ $current_time < "12:00:00" ]]; then
  echo "Good Morning!"
elif [[ $current_time < "17:00:00" ]]; then
  echo "Good Afternoon!"
elif [[ $current_time < "20:00:00" ]]; then
  echo "Good Evening!"
else
  echo "Good Night!"
fi

date +"%A, %B %d, %Y"
date +"%I:%M:%S %p"