echo "enter the number"
read num
reverse=0
org=$num
while [ $num -gt 0 ]
do
remainder=$((num%10))
reverse=$(( $reverse*10 + $remainder ))
num=$((num/10))
done
if [ $reverse -eq $org ]
then 
echo "palindrome" 
else
echo "not palindrome"
fi


