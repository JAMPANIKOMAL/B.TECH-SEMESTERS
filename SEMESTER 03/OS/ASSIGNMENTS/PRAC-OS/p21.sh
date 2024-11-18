# 21.Write An Awk Program Using Function, Which Convert Each Word In A Given Text Into Capital.

echo -e ""
read -p "Enter text: " t
echo -e "\n$t" | awk '{print toupper($0)}'

# echo "$t" | awk '{ 
#     for(i=1;i<=NF;i++) {
#         printf "%s ", toupper($i)
#     }
#     printf "\n"
# }'

