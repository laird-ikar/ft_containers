/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_egal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:56:50 by event             #+#    #+#             */
/*   Updated: 2023/02/16 15:44:55 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifdef FT
    #include "../../../inc/ft_containers.hpp"
#else
    #include <vector>
    namespace ft = std;
#endif

int main(int argc, char const *argv[])
{
    (void) argc;
    ft::vector<int> v;
    ft::vector<int> v2;
    ft::vector<int> v3(std::atoi(argv[1]));

    for (int i = 0; i < 250; i++)
    {
        v = v2;
        v = v3;
    }
    return 0;
}