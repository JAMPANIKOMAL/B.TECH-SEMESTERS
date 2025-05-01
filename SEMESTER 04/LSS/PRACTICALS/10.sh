#!/bin/bash

monitor_process()
{
    process="apache2"
    if ! pgrep "$process" > /dev/null; then
        echo "$process is not running!"
    else
        echo "$process is running."
    fi
}

monitor_process
