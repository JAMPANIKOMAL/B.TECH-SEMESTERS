#!/bin/bash

top_memory_processes()
{
    ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%mem | head -n 6
}

top_memory_processes
