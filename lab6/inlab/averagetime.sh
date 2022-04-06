#!/bin/bash

read dict

read grid

run_time=`./a.out $dict $grid| tail -1`

run_time1=`./a.out $dict $grid| tail -1`

run_time2=`./a.out $dict $grid| tail -1`

run_time3=`./a.out $dict $grid| tail -1`

run_time4=`./a.out $dict $grid| tail -1`


sum=$(((run_time +run_time1 + run_time2 +run_time3 + run_time4)/5))

echo $sum




