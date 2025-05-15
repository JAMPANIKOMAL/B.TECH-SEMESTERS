# 3. Apply awk command on the log file to get menaningful output

journalctl | awk '{print $1, $2, $3, $5, $6, $7, $8}' | head -n 10