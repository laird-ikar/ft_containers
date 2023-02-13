#!/bin/sh

#   Procédé :
#
# rm
# compile chaque binaire
# execute et redirect dans bon fichier
# r
# rm fichiers sources

rm output/*
rm -f output.png

# init files 1st line

echo "size;std_assign;ft_assign;std_assign_it;ft_assign_it" > output/test_vector_assign.txt
echo "size;std_resize;ft_resize;std_reserve;ft_reserve" > output/test_vector_resize_reserve.txt

echo "size;std_[];ft_[];std_at;ft_at;std_front;ft_front;std_back;ft_back" > output/test_vector_access.txt
echo "size;std_push_back;ft_push_back;std_pop_back;ft_pop_back" > output/test_vector_push_pop.txt

echo "size;std_insert;ft_insert;std_insert_n;ft_insert_n;std_insert_it;ft_insert_it" > output/test_vector_insert.txt
echo "size;std_erase;ft_erase;std_erase2;ft_erase2;std_swap;ft_swap;std_clear;ft_clear" > output/test_vector_erase_swap_clear.txt

#fill files

for SIZE in 10 100 200 500 1000 2000 5000 10000 20000 50000 100000 200000 500000 1000000
do
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
printf "Method >assign< done\n"

for SIZE in 10 100 200 500 1000 2000 5000 10000 20000 50000 100000 200000 500000 1000000
do
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
printf "Method >insert< done\n"

Rscript test.r


