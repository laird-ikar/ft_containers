/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectionnal_iterator.tpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:34:54 by bguyot            #+#    #+#             */
/*   Updated: 2023/01/31 10:44:48 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONNAL_ITERATOR_TPP
#define BIDIRECTIONNAL_ITERATOR_TPP

#include "bidirectionnal_iterator.hpp"

template<class T, class Distance, class Pointer, class Reference>
ft::bidirectionnal_iterator<T, Distance, Pointer, Reference>::
bidirectionnal_iterator(void)
{
	this->ptr = nullptr;
}

template<class T, class Distance, class Pointer, class Reference>
ft::bidirectionnal_iterator<T, Distance, Pointer, Reference>::
bidirectionnal_iterator(const ft::bidirectionnal_iterator<T, Distance, Pointer, Reference> &rht)
{
	*this = rht;
}

template<class T, class Distance, class Pointer, class Reference>
ft::bidirectionnal_iterator<T, Distance, Pointer, Reference>::
~bidirectionnal_iterator(void)
{}


#endif