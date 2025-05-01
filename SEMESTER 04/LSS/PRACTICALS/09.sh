#!/bin/bash

system_usage()
{
    echo "CPU Usage:"
    top -bn1 | grep "Cpu(s)"

    echo -e "\nMemory Usage:"
    free -h

    echo -e "\nDisk Usage:"
    df -h
}

system_usage
