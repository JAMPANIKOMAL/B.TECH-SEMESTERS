# === CRON SETUP INSTRUCTIONS ===
# 1. Save this file as
# 2. Make it executable:
#      chmod +x 16.sh
# 3. Edit your crontab:
#      crontab -e
# 4. Add the following line to run daily at 2:00 AM:
#      0 2 * * * path_to 16.sh
# ------------------------------------------

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
