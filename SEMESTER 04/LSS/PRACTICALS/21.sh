#!/bin/bash

resource_report()
{
    {
        echo "CPU:"
        top -bn1 | grep "Cpu(s)"
        echo -e "\nMemory:"
        free -h
        echo -e "\nDisk:"
        df -h
    } > report.txt

    echo "Report generated and saved to report.txt"
}

resource_report
