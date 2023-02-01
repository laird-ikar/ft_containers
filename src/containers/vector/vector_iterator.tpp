/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:09:44 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/01 17:04:15 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_TPP
#define VECTOR_ITERATOR_TPP

namespace ft
{
	template<class T, class Alloc>
	template<class T_it>
	vector<T, Alloc>::_iterator<T_it>::_iterator(void)
	{
		this->ptr = nullptr;
	}

	template<class T, class Alloc>
	template<class T_it>
	vector<T, Alloc>::_iterator<T_it>::_iterator(const typename vector<T, Alloc>::_iterator<T_it> &rht)
	{
		*this = rht;
	}

	template<class T, class Alloc>
	template<class T_it>
	vector<T, Alloc>::_iterator<T_it>::_iterator(typename vector<T, Alloc>::_iterator<T_it>::pointer ptr)
	{
		this->ptr = ptr;
	}

	template<class T, class Alloc>
	template<class T_it>
	vector<T, Alloc>::_iterator<T_it>::~_iterator(void)
	{
		this->ptr = nullptr;
	}

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::_iterator<T_it> &vector<T, Alloc>::_iterator<T_it>::operator=(
		const typename vector<T, Alloc>::_iterator<T_it> &rht
		)
	{
		this->ptr = rht.ptr;
	}

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::_iterator<T_it>::value_type &vector<T, Alloc>::_iterator<T_it>::operator*(void)
	{
		return *(this->ptr);
	}

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::_iterator<T_it> &vector<T, Alloc>::_iterator<T_it>::operator++(void)
	{
		this->ptr++;
		return *this;
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::_iterator<T_it> &vector<T, Alloc>::_iterator<T_it>::operator--(void)
	{
		this->ptr--;
		return *this;
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::_iterator<T_it> vector<T, Alloc>::_iterator<T_it>::operator++(int)
	{
		vector<T, Alloc>::_iterator<T_it> old(*this);
		++(*this);
		return (old);
	}

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::_iterator<T_it> vector<T, Alloc>::_iterator<T_it>::operator--(int)
	{
		vector<T, Alloc>::_iterator<T_it> old(*this);
		--(*this);
		return (old);
	}

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::_iterator<T_it> &vector<T, Alloc>::_iterator<T_it>::operator+(
		typename vector<T, Alloc>::_iterator<T_it>::difference_type n
		)
	{
		this->ptr += n;
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::_iterator<T_it> &vector<T, Alloc>::_iterator<T_it>::operator-(
		typename vector<T, Alloc>::_iterator<T_it>::difference_type n
		)
	{
		this->ptr -= n;
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	template <class T, class Allocator, class T_it>
	bool	operator==(typename vector<T, Allocator>::iterator<T_it> lht, typename vector<T, Allocator>::iterator<T_it> rht)
	{
		return lht.equals(rht);
	}

	template <class T, class Allocator, class T_it>
	bool	operator!=(typename vector<T, Allocator>::iterator<T_it> lht, typename vector<T, Allocator>::iterator<T_it> rht)
	{
		return !(lht == rht);
	}

	template <class T, class Allocator, class T_it>
	typename vector<T, Allocator>::iterator<T_it>	&operator+(
		typename vector<T, Allocator>::iterator<T_it>::difference_type n,
		typename vector<T, Allocator>::iterator<T_it> &it
		)
	{
		return (it + n);
	}

}

#endif