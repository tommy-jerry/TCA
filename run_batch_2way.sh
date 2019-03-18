#! /bin/sh -
seed=$1
tabu_size=1000
random_size=5
for file in `ls ssbse09benchmarks/*.constraints `
do  
    base_param=$(echo $file|cut -d "." -f 1)
    name=$(echo $base_param|cut -d '/' -f 2) 
    echo ./TCA ./${base_param}_2way.model ./$file 1000 $seed $tabu_size $random_size
    #./TCA ./${base_param}_2way.model ./$file 1000 $seed $tabu_size $random_size > error.${name}_${seed}_${tabu_size}_${random_size}_2way 2>&1 

done

#
#for file in `ls ssbse09benchmarks_3way/*.constraints`
#do
#    base_param=$(echo $file|cut -d "." -f 1)
#    name=$(echo $base_param|cut -d '/' -f 2) 
#    echo ./TCA ./${base_param}_3way.model ./$file 1000 200
#    ./TCA ./${base_param}_3way.model ./$file 1000 200 > error.${name}_3way 2>&1
#
#done
