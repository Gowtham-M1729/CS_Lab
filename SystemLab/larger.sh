read -p "Enter the three Number" n k m
if [ $n -gt $k ]; then
  if [ $n -gt $m ]; then
     large=$n
  else
     large=$m
  fi
else
  if [ $k -gt $m ]; then
     large=$k
  else
     large=$m
  fi
fi    
echo "large number among $n $k $m is: $large"
