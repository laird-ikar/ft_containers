/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_iterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:34:16 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/07 11:17:08 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_ITERATOR_HPP
#define IS_ITERATOR_HPP

#include "../../containers/vector/vector.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector;

	template<typename T>
	struct is_iterator
	{
		const static bool value = false;	
	};

	template<class T>
	struct is_iterator<typename ft::vector<T>::iterator >
	{
		const static bool value = false;	
	};

	template<class T>
	struct is_iterator<typename ft::vector<T>::const_iterator >
	{
		const static bool value = false;	
	};
}


#endif