#!/bin/bash

read -p "Enter the name for the first directory: " dir1
read -p "Enter the name for the second directory: " dir2
read -p "Enter the name for the third directory: " dir3

mkdir "$dir1"
mkdir "$dir2"
mkdir "$dir3"

echo "Directories $dir1, $dir2, and $dir3 have been created."
