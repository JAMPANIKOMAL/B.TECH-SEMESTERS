#!/bin/bash

log_uptime_users()
{
    while true; do
        echo "$(date): Uptime and users" >> uptime_log.txt
        uptime >> uptime_log.txt
        who | wc -l >> uptime_log.txt
        echo "---" >> uptime_log.txt
        sleep 3
    done
}

log_uptime_users
