#!/bin/bash

check_network()
{
    ping -c 4 google.com > /dev/null

    if [ $? -eq 0 ]; then
        echo "Network is up"
    else
        echo "Network is down"
    fi
}

check_network
