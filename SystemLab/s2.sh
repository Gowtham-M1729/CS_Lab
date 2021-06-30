#!/bin/bash
read -p "Enter the String" str
echo $str

str1="xyz"
#echo $str1

str2='xyz'
#echo $str
echo $str | rev 

str3=10
length=${#str}
for ((i=$length-1;i>=0;i--))
  do
    Rev=$Rev${str:$i:1}
  done

echo  "$Rev"
if [ $Rev == $str ]; then
echo "Plaindrome"
else
  echo "Not a palindrome"
fi

arr=($str $str1 $str2 10 20 30) #array consists of 5 elements

#to print no. of elements in array
echo "length of array is : ${#arr[@]}"
echo "length of array is : ${arr[@]}"
n=7
m=5

for ((i=1, pow=n; i<m; i++)); do ((pow *= n)); done
 echo $pow
#k= $(($m ** $n))
#echo "$k"
number=52
i=2
flag=0
while test $i -le `expr $number / 2`
   do
      if test `expr $number % $i` -eq 0
        then
        echo "The number is Not Prime"
        flag=1
      fi

      i=`expr $i + 1`
   done 
if test $flag -eq 1
then
echo "The number is Not Prime"
else
echo "The number is Prime $flag"
fi

