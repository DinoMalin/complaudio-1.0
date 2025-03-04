#!/bin/bash

while read -r line; do
	line=$(echo "$line" | grep "\[CMD\]")
	if [[ "$line" != "" ]]; then
		cmd=$(echo $line | sed 's/\[[^]]*\]//' | sed 's/\[//' | sed 's/\]//')
		bash -c "$cmd"
	fi
done < /dev/ttyACM0

