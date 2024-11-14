#16.Write A Shell Script To Display All Executable Files, Directories And Zero Sized Files From Current Directory.

#!/bin/bash

echo -e "\nExecutable files: "
find . -type f -executable -print

echo -e "\nDirectories: "
find . -type d -print

echo -e "\nZero-sized files: "
find . -type f -size 0 -print