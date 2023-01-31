/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectionnal_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:21:47 by bguyot            #+#    #+#             */
/*   Updated: 2023/01/31 13:43:14 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONNAL_ITERATOR_HPP
#define BIDIRECTIONNAL_ITERATOR_HPP

#include <cstddef>

namespace ft
{
	template<class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class bidirectionnal_iterator
	{
		public:
			typedef	T			value_type;
			typedef	Distance	difference_type;
			typedef	Pointer		pointer;
			typedef	Reference	reference;

		protected:
			pointer	ptr;
		
		public:
			bidirectionnal_iterator(void);
			bidirectionnal_iterator(const bidirectionnal_iterator &rht);
			virtual ~bidirectionnal_iterator();
			
			bidirectionnal_iterator			&operator=(const bidirectionnal_iterator &rht);
			bidirectionnal_iterator			&operator++(void);
			bidirectionnal_iterator			&operator++(int);
			bidirectionnal_iterator			&operator--(void);
			bidirectionnal_iterator			&operator--(int);
			const bidirectionnal_iterator	&operator*(void) const;
			bidirectionnal_iterator			&operator*(void);
	};

	template<class T>
	bool	operator==(
		bidirectionnal_iterator<T> lhs,
		bidirectionnal_iterator<T> rhs
		);
		
	template<class T>
	bool	operator!=(
		bidirectionnal_iterator<T> lhs,
		bidirectionnal_iterator<T> rhs
		);
};

#endif