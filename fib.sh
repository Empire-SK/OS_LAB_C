5echo "enter a number"
read n
t1=0
t2=1
echo "$t1"
for ((i=1;i<=n;i++))
do
echo "$t2"
next=$((t1+t2))
t1=$t2
t2=$next
done

