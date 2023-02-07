/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_iterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:34:16 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/07 13:44:20 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_ITERATOR_HPP
#define IS_ITERATOR_HPP

#include <memory>

#include "../iterator/iterator.hpp"

namespace ft
{
	template<class T>
	struct is_iterator
	{
		const static bool value = false;	
	};

	template<class T>
	struct is_iterator<>
	{
		const static bool value = true;	
	};
}


#endif