#!/bin/bash

monitor_disk_io()
{
    iostat -xz 1 3
}

monitor_disk_io
