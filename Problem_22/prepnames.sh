#!/bin/bash

sed $'s/,/\\\n/g' <names.csv >names.txt
sed -i '' 's/\"//g' names.txt
