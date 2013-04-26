#!/bin/bash

##
# Requirements: cloc, gcc
#
# usage ./benchmark.sh [subject_code] [reference_code] [iteration
#
# example ./benchmark.sh foo.c bar.c 50000
##

SUBJECT=$1
REFERENCE=$2
ITERATION=$3

# use freek implementation as validity
echo "Compiling reference $REFERENCE"
gcc main.c src/$REFERENCE -I. -o reference

# generate 50.000 data point
echo "REFERENCE"
echo
/usr/bin/time -f "%U user %S system %P cpu %e real %t memory" ./reference $ITERATION > reference.txt
#./reference 100000 > reference.txt
echo
cloc --by-file src/$REFERENCE 2> /dev/null
echo

# compiling subject
gcc main.c src/$SUBJECT -I. -o subject 


echo "SUBJECT"
echo
/usr/bin/time -f "%U user %S system %P cpu %e real %t memory" ./subject $ITERATION > subject.txt
echo

# validating output
diff subject.txt reference.txt > /dev/null
output=$?

if [ $output -eq 0 ]
then
  echo "Program is valid"
else
  echo "Program is NOT valid"
fi
echo

cloc --by-file src/$SUBJECT 2> /dev/null

#clear state
rm reference*
rm subject*
