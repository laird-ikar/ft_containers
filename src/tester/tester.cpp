/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:45:31 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/17 12:42:21 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <list>

#ifndef FT
	#include <vector>
	namespace ft = std;
#else
	#include "../../inc/ft_containers.hpp"
#endif

typedef struct s_test 
{
    const static int d = 13;
    const static int l = 7;
}   t_test;

int main()
{
	ft::vector<int> vct(5);
	ft::vector<int>::iterator it = vct.begin(), ite = vct.end();

	std::cout << "len: " << (ite - it) << std::endl;
	for (; it != ite; ++it)
		*it = (ite - it);
	it = vct.begin();
	ft::vector<int> vct_range(it, --(--ite));
	std::cout << "plouf" << std::endl;
	for (int i = 0; it != ite; ++it)
		*it = ++i * 5;

	it = vct.begin();
	ft::vector<int> vct_copy(vct);
	for (int i = 0; it != ite; ++it)
		*it = ++i * 7;
	vct_copy.push_back(42);
	vct_copy.push_back(21);

	std::cout << "\t-- PART ONE --" << std::endl;
// 	printSize(vct);
	// printSize(vct_range);
	// printSize(vct_copy);

	vct = vct_copy;
	vct_copy = vct_range;
	vct_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	// printSize(vct);
	// printSize(vct_range);
	// printSize(vct_copy);
	return (0);
}