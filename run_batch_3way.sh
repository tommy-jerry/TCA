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

for file in `ls ssbse09benchmarks_3way/*.constraints | grep -v -E '_[0-9]+\.'`
do
    for ((tabu_size=700; tabu_size<=2000; tabu_size=tabu_size+300))
    do
        for ((random_size=1; random_size<=10; random_size=random_size+2))
        do
            base_param=$(echo $file|cut -d "." -f 1)
            name=$(echo $base_param|cut -d '/' -f 2) 
            echo ./TCA ./${base_param}_3way.model ./$file 1000 $seed $tabu_size $random_size
            #./TCA ./${base_param}_3way.model ./$file 1000 $seed $tabu_size $random_size> error.${name}_${seed}_${tabu_size}_${random_size}_3way 2>&1
        done
    done

done
