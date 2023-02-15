#!/bin/sh

# remove old files
rm output/*
rm -f benchmark.png

# init files 1st line
echo "size;std_assign;ft_assign;std_assign_it;ft_assign_it" > output/test_vector_assign.txt
echo "size;std_insert;ft_insert;std_insert_n;ft_insert_n;std_insert_it;ft_insert_it" > output/test_vector_insert.txt
echo "size;std_erase;ft_erase;std_erase_it;ft_erase_it" > output/test_vector_erase.txt
echo "size;std_resize;ft_resize;std_reserve;ft_reserve" > output/test_vector_resize_reserve.txt

echo "size;std_swap;ft_swap" > output/test_vector_swap.txt
echo "size:std_clear;ft_clear" > output/test_vector_clear.txt

#   fill files
printf "\e[35mProcessing tests...\n\e[39m"

#resize
printf "\e[35mMethod\t[assign]\t\e[39m"
for SIZE in 10 100 200 500 1000 2000 5000 10000 20000 50000 100000 200000 500000 1000000
do
    printf ". "
    printf "$SIZE;" >> output/test_vector_assign.txt
    (time ./test_std_vector_assign $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_assign.txt
    printf ";" >> output/test_vector_assign.txt
    (time ./test_ft_vector_assign $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_assign.txt
    printf ";" >> output/test_vector_assign.txt
    (time ./test_std_vector_assign_it $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_assign.txt
    printf ";" >> output/test_vector_assign.txt
    (time ./test_ft_vector_assign_it $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_assign.txt
    printf "\n" >> output/test_vector_assign.txt
done
printf "\e[35mdone !\n\e[39m"

#insert
printf "\e[35mMethod\t[insert]\t\e[39m"
for SIZE in 10 100 200 500 1000 2000 5000 10000 20000 50000 100000 200000 500000 1000000
do
    printf ". "
    printf "$SIZE;" >> output/test_vector_insert.txt
    (time ./test_std_vector_insert $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_insert.txt
    printf ";" >> output/test_vector_insert.txt
    (time ./test_ft_vector_insert $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_insert.txt
    printf ";" >> output/test_vector_insert.txt
    (time ./test_std_vector_insert_n $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_insert.txt
    printf ";" >> output/test_vector_insert.txt
    (time ./test_ft_vector_insert_n $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_insert.txt
    printf ";" >> output/test_vector_insert.txt
    (time ./test_std_vector_insert_it $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_insert.txt
    printf ";" >> output/test_vector_insert.txt
    (time ./test_ft_vector_insert_it $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_insert.txt
    printf "\n" >> output/test_vector_insert.txt
done
printf "\e[35mdone !\n\e[39m"

#erase
printf "\e[35mMethod\t[erase]\t\t\e[39m"
for SIZE in 10 100 200 500 1000 2000 5000 10000 20000 50000 100000 200000 500000 1000000
do
    printf ". "
    printf "$SIZE;" >> output/test_vector_erase.txt
    (time ./test_std_vector_erase $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_erase.txt
    printf ";" >> output/test_vector_erase.txt
    (time ./test_ft_vector_erase $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_erase.txt
    printf ";" >> output/test_vector_erase.txt
    (time ./test_std_vector_erase_it $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_erase.txt
    printf ";" >> output/test_vector_erase.txt
    (time ./test_ft_vector_erase_it $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_erase.txt
    printf "\n" >> output/test_vector_erase.txt
done
printf "\e[35done !\n\e[39m"

#resize and reserve
printf "\e[35mMethods\t[reserve]/[resize]\t\t\e[39m"
for SIZE in 10 100 200 500 1000 2000 5000 10000 20000 50000 100000 200000 500000 1000000
do
    printf ". "
    printf "$SIZE;" >> output/test_vector_resize_reserve.txt
    (time ./test_std_vector_resize $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_resize_reserve.txt
    printf ";" >> output/test_vector_resize_reserve.txt
    (time ./test_ft_vector_resize $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_resize_reserve.txt
    printf ";" >> output/test_vector_resize_reserve.txt
    (time ./test_std_vector_reserve $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_resize_reserve.txt
    printf ";" >> output/test_vector_resize_reserve.txt
    (time ./test_ft_vector_reserve $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_resize_reserve.txt
    printf "\n" >> output/test_vector_resize_reserve.txt
done
printf "\e[35mdone !\n\e[39m"

#run R script to generate png
Rscript test.r 2>&1 > /dev/null


