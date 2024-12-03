# read p
# read q
# m=("$p" "$q")
# echo "${m[0]}"

#

echo "Student 1: "
read -p "Name: " n1
read -p "Class: " c1
read -p "Subjects: " s1
read -p "Percentage: " p1
read -p "Age: " a1
echo " "
n=("$n1")
c=("$c1")
s=("$s1")
p=("$p1")
a=("$a1")

for i in {0,1,2,3,4,5}; do
m=$(a[$i])
if((m -ge 17)); then
echo "Student $i:"
echo "${n[$i]}"
echo "${c[$i]}"
echo "${p[$i]}"
echo "${s[$i]}"
echo "${p[$i]}"
echo "${a[$i]}"
echo " "
elif(($(a[$i]) -ge 11)); then
echo "Student $i:"
echo "${n[$i]}"
echo "${c[$i]}"
echo "${p[$i]}"
echo "${s[$i]}"
echo "${p[$i]}"
echo "${a[$i]}"
echo " "
elif(($(a[$i]) -ge 15)); then
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