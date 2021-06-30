#!/bin/bash
read -p "Enter the size of matrix: " n
c=`expr $n - 1`

declare -A arr1
declare -A arr2
# Get the matrix elements

for ((i=0;i<=c;i++))
do
        
    for ((j=0;j<=c;j++))
    do
        read -p "enter the value of $i, $j element " arr1[$i,$j]
    done
done
for ((i=0;i<=c;i++))
do
        
    for ((j=0;j<=c;j++))
    do
        read -p "enter the value of $i, $j element " arr2[$i,$j]
    done
done
# Print the matrix

echo "First Matrix"
for ((i=0;i<=c;i++))
do
    for ((j=0;j<=c;j++))
    do
            echo -n "${arr1[$i,$j]} "
    done
    echo
done
echo "Second Matrix"
for ((i=0;i<=c;i++))
do
    for ((j=0;j<=c;j++))
    do
            echo -n "${arr2[$i,$j]} "
    done
    echo
done
for ((i=0;i<=c;i++))
do
    for ((j=0;j<=c;j++))
    do      
            k1=${arr2[$i,$j]}
            k2=${arr1[$i,$j]}
            c1=`expr $k1 + $k2`
            echo -n "$c1 "
    done
    echo
done
