/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_erase.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:50:44 by event             #+#    #+#             */
/*   Updated: 2023/02/16 17:50:52 by event            ###   ########.fr       */
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
        if (v.size() > 0)
            v.erase(v.begin() + (v.size() / 2));
    return 0;
}

int main_it(int argc, char const *argv[])
{
    (void) argc;
    ft::vector<int> v(std::atoi(argv[1]), 42);

    for (int i = 0; i < 500; i++)
        if (v.size() > 0)
            v.erase(v.begin() + (v.size() / 3), v.begin() + (v.size() / 3) * 2);
    return 0;
}

//TODO: better tests ?