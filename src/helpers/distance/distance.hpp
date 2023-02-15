/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:41:08 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/15 15:59:56 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	namespace detail {
		template<class It>
		typename std::iterator_traits<It>::difference_type 
			do_distance(It first, It last, std::input_iterator_tag)
		{
			typename std::iterator_traits<It>::difference_type result = 0;
			while (first != last) {
				++first;
				++result;
			}
			return result;
		}
		
		template<class It>
		typename std::iterator_traits<It>::difference_type 
			do_distance(It first, It last, std::random_access_iterator_tag)
		{
			return last - first;
		}
	} 
		
	template<class It>
	typename std::iterator_traits<It>::difference_type 
		distance(It first, It last)
	{
		return detail::do_distance(first, last,
								typename std::iterator_traits<It>::iterator_category());
	}
}