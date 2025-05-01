#!/bin/bash

find_large_files()
{
    find ~/ -type f -size +100M
}

find_large_files
