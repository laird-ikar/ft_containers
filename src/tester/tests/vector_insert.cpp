/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:41:11 by event             #+#    #+#             */
/*   Updated: 2023/02/15 14:23:56 by bguyot           ###   ########.fr       */
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
#elif N
    #define main_n main
#else
    #define main_it main
#endif

int main_it(int argc, char const *argv[])
{
   (void) argc;
   ft::vector<int> v1(std::atoi((argv[1])), 42);
   ft::vector<int> v2(std::atoi((argv[1])) / 50, 21);

   for (int i = 0; i < 500; i++)
      v1.insert(v1.begin() + v1.size() / 2, v2.begin(), v2.end());
   return 0;
}

int main_n(int argc, char const *argv[])
{
   (void) argc;
   ft::vector<int> v(std::atoi((argv[1])), 42);
   int n = v.size() / 10;

   for (int i = 0; i < 50; i++)
      v.insert(v.begin() + v.size() / 2, n, 21);
   return 0;
}

int main_val(int argc, char const *argv[])
{
   (void) argc;
   ft::vector<int> v(std::atoi((argv[1])), 42);

   for (int i = 0; i < 500; i++)
      v.insert(v.begin() + v.size() / 2, 21);
   return 0;
}