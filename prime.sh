echo "enter the number"
read num
for ((i=2;i<=num/2;i++))
do 
ans=$((num%i))
if [ $ans -eq 0 ]
then
echo "not prime"
exit
fi
done
echo "prime"