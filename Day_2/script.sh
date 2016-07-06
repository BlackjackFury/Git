#!/bin//bash
echo "Enter the number"
i=64
read num
while [ $i -ne 0 ]
do
let a=20%2
echo $a
if [ "$a" -eq 0 ]
then
array[$i]="0"
else 
array[$i]="1"
fi
let "i--"
let num=num/2
done
while [$i -ne 64]
do
echo array
let $i++
done
 
echo "Enter shift"

read s

echo "Enter side left or right"

read side;

        if ($side = "right")
        then 
        
        fi
