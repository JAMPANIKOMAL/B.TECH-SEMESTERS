#!/bin/bash

backup_directory()
{
    src_dir="$HOME/Documents"
    backup_dir="$HOME/backup"
    mkdir -p "$backup_dir"
    cp -r "$src_dir" "$backup_dir"
    echo "Backup completed."
}

backup_directory
