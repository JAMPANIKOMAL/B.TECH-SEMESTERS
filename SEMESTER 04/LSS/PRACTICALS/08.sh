#!/bin/bash

echo "Parent PID: $$"

# Define and run child code in a subshell using heredoc
bash << 'END_CHILD' &
echo "Child PID: $$"
echo "Child's Parent PID: $PPID"
END_CHILD

# Wait for child to finish
wait
