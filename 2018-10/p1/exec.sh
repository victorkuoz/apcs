#! /bin/bash

if [ $# -ne 0 ]; then
	cd testcase/
	zip -r ../packet.zip *
	cd ../
	exit
fi

make

rm -r -f testcase/
mkdir "testcase"

./gen
for ((i=0;i<=10;i++))
do
    time ./sol < "testcase/$i.in" > "testcase/$i.out"
done

make clean
