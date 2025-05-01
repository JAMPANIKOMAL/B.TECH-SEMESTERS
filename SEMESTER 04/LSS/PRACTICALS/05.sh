username_check() {
    u="$1"

    if [ ${#u} -lt 5 ]; then
        echo "Username should be a minimum of 5 characters"
        return 1 # Return a non-zero exit code to indicate failure
    fi

    if [ ${#u} -gt 20 ]; then
        echo "Username should be a maximum of 20 characters"
        return 1
    fi

    # Check for invalid characters.  Alphanumeric and underscore are allowed.
    if ! [[ "$u" =~ ^[a-zA-Z0-9_]+$ ]]; then
        echo "Username should contain only alphanumeric characters and underscores"
        return 1
    fi

    # Check if the username starts with a number
    if [[ "$u" =~ ^[0-9] ]]; then
        echo "Username should not start with a number"
        return 1
    fi
    
    return 0 # Return 0 to indicate success
}

read -p "Input your username: " username
username_check "$username"

if [ $? -eq 0 ]; then
    echo "Username is valid"
else
    echo "Username is invalid"
fi
