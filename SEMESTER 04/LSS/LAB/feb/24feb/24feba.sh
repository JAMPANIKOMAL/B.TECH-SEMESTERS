passwd_check()
{
    p="$1"

    if [ ${#p} -lt 8 ]; then
        echo "Password should be a minimum of 8 characters"
    fi

    flag=0
    for i in {0..9}; do
        if [[ "$p" = *$i* ]]; then
            flag=1
        fi
    done
    if [ $flag -ne 1 ]; then
        echo "Password should contain atleast 1 digit"
    fi

    flag=0
    for i in {A..Z}; do
        if [[ "$p" = *$i* ]]; then
            flag=1
        fi
    done
    if [ $flag -ne 1 ]; then
        echo "Password should contain atleast 1 uppercase letter"
    fi

    flag=0
    for i in {"!", "@", "#", "$", "%", "^", "&", "&", "*"}; do
        if [[ "$p" = *$i* ]]; then
            flag=1
        fi
    done
    if [ $flag -ne 1 ]; then
        echo "Password should contain atleast 1 special character"
    fi
}

read -p "Input your password: " passwd

passwd_check "$passwd"
