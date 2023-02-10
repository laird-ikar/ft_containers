#!/bin/sh

#   Procédé :
#
# rm
# compile chaque binaire
# execute et redirect dans bon fichier
# r
# rm fichiers sources


# rm all binary files without extension in the current directory containing "test" and all txt files

rm -f test_vector*.txt

#init files 1st line

echo "std_resize;ft_resize;std_reserve;ft_reserve" > test_vector_resize_reserve.txt
echo "std_assign;ft_assign" > test_vector_assign.txt

echo "std_[];ft_[];std_at;ft_at;std_front;ft_front;std_back;ft_back" > test_vector_access.txt
echo "std_push_back;ft_push_back;std_pop_back;ft_pop_back" > test_vector_push_pop.txt

echo "std_insert;ft_insert;std_insert2;ft_insert2;std_insert3;ft_insert3" > test_vector_insert.txt
echo "std_erase;ft_erase;std_erase2;ft_erase2;std_swap;ft_swap;std_clear;ft_clear" > test_vector_erase_swap_clear.txt

time ./test_ftvector_assign | grep "real" | cut -f2 >> test_vector_assign.txt
echo ";" >> test_vector_assign.txt


