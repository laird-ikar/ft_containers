/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_erase.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:50:44 by event             #+#    #+#             */
/*   Updated: 2023/02/15 18:07:10 by bguyot           ###   ########.fr       */
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
    ft::vector<int> v(std::atoi(argv[1]), 42);

    for (int i = 0; i < 500; i++)
       v.erase(v.begin() + (v.size() / 2));
    return 0;
}

int main_it(int argc, char const *argv[])
{
    (void) argc;
    ft::vector<int> v(std::atoi(argv[1]), 42);

    for (int i = 0; i < 500; i++)
       v.erase(v.begin() + (v.size() / 3), v.begin() + (v.size() / 3) * 2);
    return 0;
}