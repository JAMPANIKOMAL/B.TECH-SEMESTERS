#!/bin/bash

report_file="/tmp/sys_report.txt"

{
    echo "System Report - $(date)"
    echo "=============================="
    echo -e "\nCPU Usage:"
    top -bn1 | grep "Cpu(s)"
    echo -e "\nMemory Usage:"
    free -h
    echo -e "\nDisk Usage:"
    df -h
} > "$report_file"

# Send the report via email
cat "$report_file" | mail -s "System Report" admin@example.com

echo "Report sent to admin@example.com"
