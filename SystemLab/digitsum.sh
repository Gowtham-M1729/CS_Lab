read -p "Enter the Number" n
n1=$n
while [ $n -ne "0" ]
   do
     dig=$((n%10))
     sum=$((sum+dig))
     n=$((n/10))
   done
echo "Sum of digits of $n is: $sum"
