# ------------------------------------------
# === CRON SETUP INSTRUCTIONS ===
# 1. Save this file
# 2. Make it executable:
#      chmod +x 17.sh
# 3. Edit your crontab:
#      crontab -e
# 4. Add the following line to run daily at midnight:
#      0 0 * * * path_to 17.sh
# ------------------------------------------

#!/bin/bash

clean_temp()
{
    rm -rf /tmp/*
    echo "$(date): Temporary files cleaned."
}

clean_temp
