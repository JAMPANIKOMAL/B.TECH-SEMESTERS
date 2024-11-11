#Write A Shell Script To Generate Mark Sheet Of A Student. Take 3 Subjects, Calculate And Display Total Marks, Percentage And Class Obtained By The Student.


echo "Enter marks for three subjects:"

read -p "Enter marks for Subject 1: " s1
read -p "Enter marks for Subject 2: " s2
read -p "Enter marks for Subject 3: " s3

total=$((s1 + s2 + s3))
percentage=$((total * 100 / 300))

echo "Total Marks: $total"
echo "Percentage: $percentage%"

if [[ $percentage -ge 90 ]]; then
  class="O"
elif [[ $percentage -ge 80 ]]; then
  class="A+"
elif [[ $percentage -ge 70 ]]; then
  class="A"
elif [[ $percentage -ge 60 ]]; then
  class="B+"
elif [[ $percentage -ge 55]]; then
  class="B"
elif [[ $percentage -ge 50]]; then
  class="C"
else
  class="F"
fi

echo "Class Obtained: $class"