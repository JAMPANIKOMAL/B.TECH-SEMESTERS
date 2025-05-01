#!/bin/bash

child_process()
{
    echo "Parent PID: $$"
    child_pid=$( (echo "Child PID: $$") & wait $! )
}

child_process
