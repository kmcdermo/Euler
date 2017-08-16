#!/bin/bash

sed $'s/,/\\\n/g' <words.csv >words.txt
sed -i '' 's/\"//g' words.txt
