#!/bin/bash

for ((i=1; i<=10; i++))
do
    nohup ./run_batch_2way.sh $i >>nohup2.out 2>&1 &
    #echo $i,$j,$k
done
