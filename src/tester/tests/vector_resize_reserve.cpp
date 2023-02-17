/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize_reserve.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:26:02 by event             #+#    #+#             */
/*   Updated: 2023/02/16 16:42:21 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifdef FT
    #include "../../../inc/ft_containers.hpp"
#else
    #include <vector>
    namespace ft = std;
#endif

#ifdef SIZE
    #define main_resize main
#else  
    #define main_reserve main
#endif

int main_resize(int argc, char const *argv[])
{
    (void) argc;
    ft::vector<int> v(std::atoi(argv[1]));
    for (int i = 0; i < 500; i++)
        v.resize(std::atoi(argv[1]) / 500 * (500 - i));
    for (int i = 0; i < 500; i++)
        v.resize(std::atoi(argv[1]) / 500 * i);
    return 0;
}

int main_reserve(int argc, char const *argv[])
{
    (void) argc;
    ft::vector<int> v(std::atoi(argv[1]));
    for (int i = 0; i < 500; i++)
        v.reserve(std::atoi(argv[1]) / 500 * (500 - i));
    for (int i = 0; i < 500; i++)
        v.reserve(std::atoi(argv[1]) / 500 * i);
    return 0;
}