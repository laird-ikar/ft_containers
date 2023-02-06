/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:45:31 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/06 14:54:03 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_containers.hpp"

int main()
{
    ft::vector<int> v;
    ft::vector<int> v2(5, 42);
    ft::vector<int> v3(v2);
    // ft::vector<int> v4(v2.begin(), v2.end());
    // ft::vector<int> v5(v2.rbegin(), v2.rend());
    

    (void) v;
    (void) v2;
    (void) v3;
    // (void) v4;
    // (void) v5;
}