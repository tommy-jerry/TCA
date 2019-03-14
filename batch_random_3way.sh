#!/bin/bash

for ((i=1; i<=10; i++))
do
    nohup ./run_batch_3way.sh $i >>nohup.out 2>&1 &
done
