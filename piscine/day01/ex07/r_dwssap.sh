cat /etc/passwd | grep -v '#' | cut -d : -f1 | sed -n 'n;p' | rev | sort -r |  tr '\n' ',' | cut -d , -f $FT_LINE1-$FT_LINE2 | sed -e ' s/.*/&./' | sed 's/,/, /g' | tr -d '\n'
