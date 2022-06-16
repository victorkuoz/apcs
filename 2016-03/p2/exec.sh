#! /bin/bash

if [ $# -ne 0 ]; then
	cd testcase/
	zip -r ../testcase.zip *
	cd ../
	rm -r -f testcase/
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
