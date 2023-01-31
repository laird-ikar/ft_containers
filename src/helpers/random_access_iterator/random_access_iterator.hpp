/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:06:52 by bguyot            #+#    #+#             */
/*   Updated: 2023/01/26 18:09:06 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "../bidirectionnal_iterator/bidirectionnal_iterator.hpp"

namespace ft {
	template<class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class random_access_iterator: public bidirectionnal_iterator<T, Distance, Pointer, Reference>
	{
		public:
			
	};
	template<class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	bool	operator<(
		bidirectionnal_iterator<T, Distance, Pointer, Reference> lhs,
		bidirectionnal_iterator<T, Distance, Pointer, Reference> rhs
		);
	template<class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	bool	operator>(
		bidirectionnal_iterator<T, Distance, Pointer, Reference> lhs,
		bidirectionnal_iterator<T, Distance, Pointer, Reference> rhs
		);
	template<class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	bool	operator>=(
		bidirectionnal_iterator<T, Distance, Pointer, Reference> lhs,
		bidirectionnal_iterator<T, Distance, Pointer, Reference> rhs
		);
	template<class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	bool	operator<=(
		bidirectionnal_iterator<T, Distance, Pointer, Reference> lhs,
		bidirectionnal_iterator<T, Distance, Pointer, Reference> rhs
		);
};

#endif