# 20.Write A Shell Script That Finds Total No. Of Users And Finds Out How Many Of Them Are Currently Logged In.

echo "Total No. of users: $(cat /etc/passwd | wc -l)"
echo "Total No. of logged in users: $(who | wc -l)"