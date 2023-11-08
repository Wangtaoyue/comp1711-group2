#!/bin/bash

read -p "Enter the name for the first file: " file1
read -p "Enter information for $file1: " info1
echo "$info1" > "$file1"

read -p "Enter the name for the second file: " file2
read -p "Enter information for $file2: " info2
echo "$info2" > "$file2"

read -p "Enter the name for the third file: " file3
read -p "Enter information for $file3: " info3
echo "$info3" > "$file3"

echo "Files $file1, $file2, and $file3 have been created with user-provided information."
