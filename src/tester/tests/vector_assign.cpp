/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_assign.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:29:41 by event             #+#    #+#             */
/*   Updated: 2023/02/13 18:03:21 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifdef FT
    #include "../../../inc/ft_containers.hpp"
#else
    #include <vector>
    namespace ft = std;
#endif

#ifdef VAL
    #define main_val main
#else
    #define main_it main
#endif


int main_val(int argc, char const *argv[])
{
    (void) argc;
    ft::vector<int> v1;

    for (size_t i = 0; i < 500; i++)
        v1.assign(std::atoi(argv[1]), 21);
    return 0;
}

int main_it(int argc, char const *argv[])
{
    (void) argc;
    ft::vector<int> v1;
    ft::vector<int> v2(std::atoi(argv[1]), 21);

    for (size_t i = 0; i < 500; i++)
        v1.assign(v2.begin(), v2.end());
    return 0;
}