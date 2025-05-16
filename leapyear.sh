echo "Enter a year"
read y
if [ $((y%4)) -eq 0 ] || [ $((y%400)) -eq 0 ] && [ $((y%100)) -ne 0 ]
then
echo "leap year"
else 
echo "not leap"
fi