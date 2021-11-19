#! /bin/bash

make

mkdir "testcase"

./gen
for ((i=0;i<=10;i++))
do
    if [ $i -lt 10 ]; then
        ./sol < "testcase/0$i.in" > "testcase/0$i.ans"
    else
        ./sol < "testcase/$i.in" > "testcase/$i.ans"
    fi
done

make clean
