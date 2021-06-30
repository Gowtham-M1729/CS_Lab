echo "enter m and n range" 
read m 
read n 
flag=0 
echo -n "prime nos in given range are " 
for((i=$m;i<=$n;i++)) 
do 
flag=0 
for((j=2;j<=i/2;j++)) 
do 
if [ $((i%j)) == 0 ];then 
flag=1 
break 
fi 
done 
if [ $flag == 0 ];then 
echo -n "$i " 
fi 
done
