#!/bin/bash

search_keyword()
{
    file="$1"
    keyword="$2"
    if [[ -f "$file" && -n "$keyword" ]]; then
        awk -v kw="$keyword" 'tolower($0) ~ kw' "$file"
    else
        echo "Usage: $0 <file> <keyword>"
    fi
}

search_keyword "report.txt" "error"
