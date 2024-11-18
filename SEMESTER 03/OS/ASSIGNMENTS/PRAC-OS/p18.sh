#18.Write A Shell Script To Validate The Entered Date. (E.G. Date Format Is: Dd-Mm-Yyyy).

#!/bin/bash

read -p "Enter a date in DD-MM-YYYY format: " date_str

if [[ ! $date_str =~ ^[0-9]{2}-[0-9]{2}-[0-9]{4}$ ]]; then
  echo "Invalid date format. Please enter a date in DD-MM-YYYY format."
  exit 1
fi

day=$(echo $date_str | cut -d- -f1)
month=$(echo $date_str | cut -d- -f2)
year=$(echo $date_str | cut -d- -f3)

if [[ $day -lt 1 || $day -gt 31 || $month -lt 1 || $month -gt 12 ]]; then
  echo "Invalid date. Please check the day and month values."
  exit 1
fi

if [[ $month -eq 2 ]]; then
  if [[ $((year % 4)) -eq 0 && ($((year % 100)) -ne 0 || $((year % 400)) -eq 0) ]]; then
    if [[ $day -gt 29 ]]; then
      echo "Invalid date. February can have maximum 29 days in a leap year."
      exit 1
    fi
  elif [[ $day -gt 28 ]]; then
    echo "Invalid date. February can have maximum 28 days in a non-leap year."
    exit 1
  fi
fi

if [[ $month -eq 4 || $month -eq 6 || $month -eq 9 || $month -eq 11 ]]; then
  if [[ $day -gt 30 ]]; then
    echo "Invalid date. This month can have maximum 30 days."
    exit 1
  fi
fi

echo "Valid date."