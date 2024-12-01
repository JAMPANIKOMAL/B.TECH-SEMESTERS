echo -n "Enter the marks of the student: "
read marks
if [ $marks -ge 90 ]; then
grade="A+"
elif [ $marks -ge 80 ]; then
grade="A"
elif [ $marks -ge 70 ]; then
grade="B"
elif [ $marks -ge 60 ]; then
grade="C"
elif [ $marks -ge 50 ]; then
grade="D"
else
grade="F"
fi
echo "The grade of the student is: $grade"