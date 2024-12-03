# Write a shell script to create a database of following items: List of students, class, subjects, percentage, age and divide differnet list according to age bracket --> 5 to 10, 11 to 16, 17 to 21.

echo "Student 1: "
read -p "Name: " n1
read -p "Class: " c1
read -p "Subjects: " s1
read -p "Percentage: " p1
read -p "Age: " a1
echo " "

echo "Student 2: "
read -p "Name: " n2
read -p "Class: " c2
read -p "Subjects: " s2
read -p "Percentage: " p2
read -p "Age: " a2
echo " "

echo "Student 3: "
read -p "Name: " n3
read -p "Class: " c3
read -p "Subjects: " s3
read -p "Percentage: " p3
read -p "Age: " a3
echo " "

echo "Student 4: "
read -p "Name: " n4
read -p "Class: " c4
read -p "Subjects: " s4
read -p "Percentage: " p4
read -p "Age: " a4
echo " "

echo "Student 5: "
read -p "Name: " n5
read -p "Class: " c5
read -p "Subjects: " s5
read -p "Percentage: " p5
read -p "Age: " a5
echo " "

echo "Student 6: "
read -p "Name: " n6
read -p "Class: " c6
read -p "Subjects: " s6
read -p "Percentage: " p6
read -p "Age: " a6
echo " "

n=("$n1" "$n2" "$n3" "$n4" "$n5" "$n6")
c=("$c1" "$c2" "$c3" "$c4" "$c5" "$c6")
s=("$s1" "$s2" "$s3" "$s4" "$s5" "$s6")
p=("$p1" "$p2" "$p3" "$p4" "$p5" "$p6")
a=("$a1" "$a2" "$a3" "$a4" "$a5" "$a6")


for i in {0,1,2,3,4,5}; do
echo "Student $i:"
echo "${n[$i]}"
echo "${c[$i]}"
echo "${p[$i]}"
echo "${s[$i]}"
echo "${p[$i]}"
echo "${a[$i]}"
echo " "
done

echo "Grouping By age: "
for i in {0,1,2,3,4,5}; do
if[[$(a[$i]) -ge 17]]; then
echo "Student $i:"
echo "${n[$i]}"
echo "${c[$i]}"
echo "${p[$i]}"
echo "${s[$i]}"
echo "${p[$i]}"
echo "${a[$i]}"
echo " "
elif[[$(a[$i]) -ge 11]]; then
echo "Student $i:"
echo "${n[$i]}"
echo "${c[$i]}"
echo "${p[$i]}"
echo "${s[$i]}"
echo "${p[$i]}"
echo "${a[$i]}"
echo " "
elif[[$(a[$i]) -ge 15]]; then
echo "Student $i:"
echo "${n[$i]}"
echo "${c[$i]}"
echo "${p[$i]}"
echo "${s[$i]}"
echo "${p[$i]}"
echo "${a[$i]}"
echo " " 
else
echo "Student $i:"
echo "${n[$i]}"
echo "${c[$i]}"
echo "${p[$i]}"
echo "${s[$i]}"
echo "${p[$i]}"
echo "${a[$i]}"
echo " " 
fi
done