#! /bin/sh -
#for file in `ls ssbse09benchmarks/*.constraints`
#do
#      
#    base_param=$(echo $file|cut -d "." -f 1)
#    name=$(echo $base_param|cut -d '/' -f 2) 
#    echo ./TCA ./${base_param}_2way.model ./$file 1000 200
#    ./TCA ./${base_param}_2way.model ./$file 1000 200 > error.${name}_2way 2>&1 
#
#done

seed=$1

for file in `ls ssbse09benchmarks_3way/*.constraints`
do
    base_param=$(echo $file|cut -d "." -f 1)
    name=$(echo $base_param|cut -d '/' -f 2) 
    echo ./TCA ./${base_param}_3way.model ./$file 1000 $seed
    ./TCA ./${base_param}_3way.model ./$file 1000 $seed > error.${name}_${seed}_3way 2>&1

done
