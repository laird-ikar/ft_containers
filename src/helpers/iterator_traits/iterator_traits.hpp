/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:59:40 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/06 15:54:40 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft
{
	/**
	 * @tparam	It	The iterator type we are to trait (?)
	 */
	template<class It>
	class iterator_traits
	{
		public:
			typedef typename It::difference_type	difference_type;
	};	
}


#endif