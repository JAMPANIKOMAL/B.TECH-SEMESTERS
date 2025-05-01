#!/bin/bash

extract_errors()
{
    grep -i "error" /var/log/syslog
}

extract_errors
