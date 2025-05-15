# 2. Utilise the system log file and display file essential system information using grep command

journalctl | grep -i "error" | head -n 3
journalctl | grep -i "warning" | head -n 3