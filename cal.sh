echo "enter the first number"
read n1
echo "enter the operator"
read opr
echo "enter the second number"
read n2

case $opr in

+)
result=$((n1+n2))
echo "sum is $result"
;;
-)
result=$((n1-n2))
echo "difference is $result"
;;
*)
result=$((n1 \* n2))
echo "product is $result"
;;
/)
result=$((n1/n2)) 
echo "quotient is $result"
;;


esac

