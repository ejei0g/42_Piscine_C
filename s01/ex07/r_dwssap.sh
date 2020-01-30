#!/usr/bin/env bash
cat /etc/passwd | sed '/^#/d' | awk -F: '{print $1}' | awk "NR%2==0" | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2"p | sed 's/$/, /' | tr -d '\n' | sed 's/, $/./' | tr -d '\n'
