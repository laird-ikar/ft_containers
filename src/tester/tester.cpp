/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:45:31 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/09 13:50:22 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../../inc/ft_containers.hpp"
// namespace ft = std;
// #include <vector>

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
		std::cout << "dereference (rvalue) (commenting cause it doesnt compile, obv)" << std::endl;
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
    return 0;
}