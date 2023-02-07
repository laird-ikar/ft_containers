/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:45:31 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/07 13:53:59 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_containers.hpp"

int main()
{
    ft::vector<int> v;
    ft::vector<int> v2(42, 5);
    ft::vector<int> v3(v2);
    ft::vector<int>::iterator it(v2.begin());
    ft::vector<int> v4(v2.begin(), v2.end());
    // ft::vector<int> v5(v2.rbegin(), v2.rend());
    

    (void) v;
    (void) v2;
    (void) v3;
    (void) v4;
    // (void) v5;

    ft::vector<int>::iterator it(nullptr);
    ft::vector<int>::iterator it2(nullptr);

    return (it == it2);
}