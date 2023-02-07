/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:59:40 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/07 17:27:11 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft
{
	/**
	 * @brief Iterator traits class
	 * @tparam It Iterator type
	 */
	template <typename It>
	struct iterator_traits
	{
		typedef typename It::difference_type	difference_type;
		typedef typename It::value_type			value_type;
		typedef typename It::pointer			pointer;
		typedef typename It::reference			reference;
		typedef typename It::iterator_category	iterator_category;
	};

	/**
	 * @brief Iterator traits class for pointer
	 * @tparam T Pointer type
	 */
	template <typename T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	/**
	 * @brief Iterator traits class for const pointer
	 * @tparam T Const pointer type
	 */
	template <typename T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};
}


#endif