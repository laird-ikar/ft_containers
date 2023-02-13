/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:45:31 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/13 12:53:05 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifdef FT
	#include "../../inc/ft_containers.hpp"
#else
	#include <vector>
	namespace ft = std;
#endif

typedef struct s_test 
{
    const static int d = 13;
    const static int l = 7;
}   t_test;

int main()
{
	std::cout << "TESTING VECTOR::ITERATOR PROPERTIES" << std::endl;
   {
		std::cout << "default constructible" << std::endl;
		ft::vector<t_test>::iterator	it_default;
		ft::vector<t_test>				v(42);
		std::cout << "copy constructible" << std::endl;
		ft::vector<t_test>::iterator	it(v.begin());
		ft::vector<t_test>::iterator	it_copy;
		std::cout << "copy assignable" << std::endl;
		it_copy = it;
		std::cout << "destructible" << std::endl;
		ft::vector<t_test>::iterator	*tmp = new ft::vector<t_test>::iterator();
		delete tmp;
		std::cout << "increment" << std::endl;
		++it;
		it++;
		std::cout << "== & != comparaison" << std::endl;
		(void) (it == it_copy);
		(void) (it != it_copy);
		std::cout << "dereference (lvalue)" << std::endl;
		(void) *it;
		(void) it->d;
		std::cout << "dereference (rvalue)" << std::endl;
		*it = t_test();
		*it++ = t_test();
		std::cout << "multipass" << std::endl;
		(void) *it_copy;
		std::cout << "decrement" << std::endl;
		--it;
		it--;
		*it--;
		std::cout << "arithmetic + & -" << std::endl;
		(void) (it + 5);
		(void) (5 + it);
		(void) (it - 5);
		(void) (it - it_copy);
		std::cout << "inequality comparaison" << std::endl;
		(void) (it > it_copy);
		(void) (it >= it_copy);
		(void) (it <= it_copy);
		(void) (it < it_copy);
		std::cout << "arithmetic assignation (+= -=)" << std::endl;
		it += 5;
		it -= 5;
		std::cout << "crochet crochet" << std::endl;
		(void) it[5];
	}
	std::cout << std::endl;

	std::cout << "TESTING CONST VECTOR::CONST_ITERATOR PROPERTIES" << std::endl;
   {
		std::cout << "default constructible" << std::endl;
		ft::vector<t_test>::const_iterator	it_default;
		const ft::vector<t_test>				v(42);
		std::cout << "copy constructible" << std::endl;
		ft::vector<t_test>::const_iterator	it(v.begin());
		ft::vector<t_test>::const_iterator	it_copy;
		std::cout << "copy assignable" << std::endl;
		it_copy = it;
		std::cout << "destructible" << std::endl;
		ft::vector<t_test>::const_iterator	*tmp = new ft::vector<t_test>::const_iterator();
		delete tmp;
		std::cout << "increment" << std::endl;
		++it;
		it++;
		std::cout << "== & != comparaison" << std::endl;
		(void) (it == it_copy);
		(void) (it != it_copy);
		std::cout << "dereference (lvalue)" << std::endl;
		(void) *it;
		(void) it->d;
		std::cout << "dereference (rvalue) (should not compile since it is const)" << std::endl;
		// *it = t_test();
		// *it++ = t_test();
		std::cout << "multipass" << std::endl;
		(void) *it_copy;
		std::cout << "decrement" << std::endl;
		--it;
		it--;
		*it--;
		std::cout << "arithmetic + & -" << std::endl;
		(void) (it + 5);
		(void) (5 + it);
		(void) (it - 5);
		(void) (it - it_copy);
		std::cout << "inequality comparaison" << std::endl;
		(void) (it > it_copy);
		(void) (it >= it_copy);
		(void) (it <= it_copy);
		(void) (it < it_copy);
		std::cout << "arithmetic assignation (+= -=)" << std::endl;
		it += 5;
		it -= 5;
		std::cout << "crochet crochet" << std::endl;
		(void) it[5];
	}
	std::cout << std::endl;

	std::cout << "TESTING VECTORS" << std::endl;
	{
		ft::vector<int> v;

		std::cout << "filling with ints using pushback():" << std::endl;
		for (int i = 0 ; i <= 42 ; i++)
		{
			v.push_back(i);
		}

		std::cout << "priting via begin() and end():" << std::endl;
		for (ft::vector<int>::iterator it = v.begin() ; it != v.end() ; it++)
		{
			std::cout << *it << "; ";
		}
		std::cout << std::endl;

		std::cout << "priting via rbegin() and rend():" << std::endl;
		for (ft::vector<int>::reverse_iterator it = v.rbegin() ; it != v.rend() ; it++)
		{
			std::cout << *it << "; ";
		}
		std::cout << std::endl;
		
		std::cout << "testing element access" << std::endl;
		std::cout << "v[21]:" << v[21] << "; v.at(21):" << v.at(21) 
			<< "; v.front():" << v.front() << "; v.back():" << v.back()
			<< std::endl;
		
		std::cout << "testing capacity reading" << std::endl;
		std::cout << "v.empty():" << v.empty() << "; v.size():" << v.size()
			<< "; v.max_size():" << v.max_size() << "; v.capacity():" << v.capacity()
			<< std::endl;
		
		std::cout << "reserving 100" << std::endl;
		v.reserve(100);
		std::cout << "testing capacity reading" << std::endl;
		std::cout << "v.empty():" << v.empty() << "; v.size():" << v.size()
			<< "; v.max_size():" << v.max_size() << "; v.capacity():" << v.capacity()
			<< std::endl;
		
		std::cout << "clearing" << std::endl;
		v.clear();
		std::cout << "testing capacity reading" << std::endl;
		std::cout << "v.empty():" << v.empty() << "; v.size():" << v.size()
			<< "; v.max_size():" << v.max_size() << "; v.capacity():" << v.capacity()
			<< std::endl;
		std::cout << "resize to 21" << std::endl;
		v.resize(21);
		std::cout << "priting via begin() and end():" << std::endl;
		for (ft::vector<int>::iterator it = v.begin() ; it != v.end() ; it++)
		{
			std::cout << *it << "; ";
		}
		std::cout << std::endl;
		std::cout << "testing capacity reading" << std::endl;
		std::cout << "v.empty():" << v.empty() << "; v.size():" << v.size()
			<< "; v.max_size():" << v.max_size() << "; v.capacity():" << v.capacity()
			<< std::endl;
		std::cout << "resize to 42 with value 42" << std::endl;
		v.resize(42, 42);
		std::cout << "priting via begin() and end():" << std::endl;
		for (ft::vector<int>::iterator it = v.begin() ; it != v.end() ; it++)
		{
			std::cout << *it << "; ";
		}
		std::cout << std::endl;
		std::cout << "testing capacity reading" << std::endl;
		std::cout << "v.empty():" << v.empty() << "; v.size():" << v.size()
			<< "; v.max_size():" << v.max_size() << "; v.capacity():" << v.capacity()
			<< std::endl;
		std::cout << "erasing elements 12 through 19" << std::endl;
		v.erase(v.begin() + 12, v.begin() + 19);
		std::cout << "priting via begin() and end():" << std::endl;
		for (ft::vector<int>::iterator it = v.begin() ; it != v.end() ; it++)
		{
			std::cout << *it << "; ";
		}
		std::cout << std::endl;
		std::cout << "testing capacity reading" << std::endl;
		std::cout << "v.empty():" << v.empty() << "; v.size():" << v.size()
			<< "; v.max_size():" << v.max_size() << "; v.capacity():" << v.capacity()
			<< std::endl;
		ft::vector<int> v2(66, 6);
		std::cout << "assigning v2 to v" << std::endl;
		v.assign(v2.begin(), v2.end());
		std::cout << "priting via begin() and end():" << std::endl;
		for (ft::vector<int>::iterator it = v.begin() ; it != v.end() ; it++)
		{
			std::cout << *it << "; ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
    return 0;
}