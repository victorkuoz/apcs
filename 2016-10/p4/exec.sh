#! /bin/bash

make

rm -r -f testcase/
mkdir "testcase"

./gen
for ((i=0;i<=10;i++))
do
    ./sol < "testcase/$i.in" > "testcase/$i.out"
done

if [ $# -ne 0 ]; then
	cd testcase/
	zip -r ../packet.zip *
	cd ../
fi

make clean
