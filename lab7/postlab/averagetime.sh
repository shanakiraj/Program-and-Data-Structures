#!/bin/bash

echo "enter the exponent for counter.cpp:"
read exponent

if [[ $exponent = "quit" ]] ; then
    exit 1
fi

counter=5
total=0
avg=0

for i in {1..5} ; do
    run_time=`./a.out $exponent| tail -1`
    echo $run_time
    total=$((total+run_time))
done

echo $total
avg=$((total/5))
echo $avg

    

