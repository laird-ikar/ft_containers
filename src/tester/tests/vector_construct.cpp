/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_construct.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:54:21 by event             #+#    #+#             */
/*   Updated: 2023/02/16 17:13:46 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifdef FT
    #include "../../../inc/ft_containers.hpp"
#else
    #include <vector>
    namespace ft = std;
#endif

#ifdef RANGE
    #define main_range main
#else
    #define main_val main
#endif

int main_val(int argc, char const *argv[])
{
    (void) argc;

    for (int i = 0; i < 500; i++)
    {
        ft::vector<int> v(std::atoi(argv[1]));
    }
    return 0;
}

int main_range(int argc, char const *argv[])
{
    (void) argc;
    ft::vector<int> _v(std::atoi(argv[1]));

    for (int i = 0; i < 500; i++)
    {
        ft::vector<int> v(_v.begin(), _v.end());
    }
    return 0;
}