#!/bin/bash

log_with_timestamp()
{
    echo "$(date): Running example log message" >> script.log
}

log_with_timestamp
