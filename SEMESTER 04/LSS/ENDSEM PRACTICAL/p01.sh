# 1. Create a file and identify the soft and hardlink of the file.

touch t1.txt
# touch t2.txt
# touch t3.txt
# touch t4.txt

ln t1.txt t2.txt   

ln -s t1.txt t3.txt

ls -li t1.txt t2.txt t3.txt