#!/bin/sh

# remove old files
rm output/*
rm -f benchmark_v.png

# init files 1st line
echo "size;std_assign;ft_assign;std_assign_it;ft_assign_it" > output/test_vector_assign.txt
echo "size;std_insert;ft_insert;std_insert_n;ft_insert_n;std_insert_it;ft_insert_it" > output/test_vector_insert.txt
echo "size;std_erase;ft_erase;std_erase_it;ft_erase_it" > output/test_vector_erase.txt
echo "size;std_resize;ft_resize;std_reserve;ft_reserve" > output/test_vector_resize_reserve.txt
echo "size;std_egal;ft_egal" > output/test_vector_egal.txt
echo "size;std_construct;ft_construct;std_construct_range;ft_construct_range" > output/test_vector_construct.txt

#   fill files
printf "\e[35m\nProcessing tests...\n\e[39m"

#resize
printf "\t\e[35mMethod\t[assign]\t\t\e[39m"
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
printf "\t\e[35mdone !\n\e[39m"

#insert
printf "\t\e[35mMethod\t[insert]\t\t\e[39m"
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
printf "\t\e[35mdone !\n\e[39m"

#erase
printf "\t\e[35mMethod\t[erase]\t\t\t\e[39m"
for SIZE in 10 100 1000 2000 5000 8000 8500 10000 20000 50000 100000 200000 500000 1000000
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
printf "\t\e[35mdone !\n\e[39m"

#operator=
printf "\t\e[35mMethod\t[operator=]\t\t\e[39m"
for SIZE in 10 100 200 500 1000 2000 5000 10000 20000 50000 100000 200000 500000 1000000
do
    printf ". "
    printf "$SIZE;" >> output/test_vector_egal.txt
    (time ./test_std_vector_egal $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_egal.txt
    printf ";" >> output/test_vector_egal.txt
    (time ./test_ft_vector_egal $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_egal.txt
    printf "\n" >> output/test_vector_egal.txt
done
printf "\t\e[35mdone !\n\e[39m"

#clear
printf "\t\e[35mMethods\t[constructor]\t\t\e[39m"
for SIZE in 10 100 200 500 1000 2000 5000 10000 20000 50000 100000 200000 500000 1000000
do
    printf ". "
    printf "$SIZE;" >> output/test_vector_construct.txt
    (time ./test_std_vector_construct $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_construct.txt
    printf ";" >> output/test_vector_construct.txt
    (time ./test_ft_vector_construct $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_construct.txt
    printf ";" >> output/test_vector_construct.txt
    (time ./test_std_vector_construct_range $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_construct.txt
    printf ";" >> output/test_vector_construct.txt
    (time ./test_ft_vector_construct_range $SIZE) 2>&1 | grep "real" | cut -f2 | cut -f2 -d'm' | cut -f1 -d's' | tr -d '\n' >> output/test_vector_construct.txt
    printf "\n" >> output/test_vector_construct.txt
done
printf "\t\e[35mdone !\n\e[39m"

#resize and reserve
printf "\t\e[35mMethods\t[reserve]/[resize]\t\e[39m"
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
printf "\t\e[35mdone !\n\e[39m"

# sed -i.bak 's/\./,/g' output/test_vector_assign.txt
# sed -i.bak 's/\./,/g' output/test_vector_insert.txt
# sed -i.bak 's/\./,/g' output/test_vector_erase.txt
# sed -i.bak 's/\./,/g' output/test_vector_resize_reserve.txt
# rm -f output/*.bak

#run R script to generate png
Rscript benchmark_vector.r > /dev/null
