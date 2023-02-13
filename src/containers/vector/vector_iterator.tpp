
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:30:43 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/10 14:29:22 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{

	/******************** CONSTRUCTORS & DESTRUCTORS **************************/

	template<class T, class Alloc>
	template<class T_it>
	vector<T, Alloc>::template _iterator<T_it>::_iterator(void)
	{
		this->ptr = nullptr;
	}

	template<class T, class Alloc>
	template<class T_it>
	vector<T, Alloc>::template _iterator<T_it>::_iterator(const typename vector<T, Alloc>::template _iterator<T_it> &rht)
	{
		*this = rht;
	}

	template<class T, class Alloc>
	template<class T_it>
	vector<T, Alloc>::template _iterator<T_it>::_iterator(vector<T, Alloc>::template _iterator<T_it>::pointer ptr)
	{
		this->ptr = ptr;
	}

	template<class T, class Alloc>
	template<class T_it>
	vector<T, Alloc>::template _iterator<T_it>::~_iterator(void)
	{
		this->ptr = nullptr;
	}

	/************************** ASSIGNATION OPERATORS *************************/

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::template _iterator<T_it> &vector<T, Alloc>::template _iterator<T_it>::operator=(
		const typename vector<T, Alloc>::template _iterator<T_it> &rht
		)
	{
		this->ptr = rht.ptr;
		return (*this);
	}

	/*************************** ARITHMETIC OPERATORS *************************/

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::template _iterator<T_it>
		&vector<T, Alloc>::template _iterator<T_it>::operator++(void)
	{
		this->ptr++;
		return *this;
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::template _iterator<T_it> &vector<T, Alloc>::template _iterator<T_it>::operator--(void)
	{
		this->ptr--;
		return *this;
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::template _iterator<T_it> vector<T, Alloc>::template _iterator<T_it>::operator++(int)
	{
		typename vector<T, Alloc>::template _iterator<T_it> old(*this);
		++(*this);
		return (old);
	}

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::template _iterator<T_it> vector<T, Alloc>::template _iterator<T_it>::operator--(int)
	{
		typename vector<T, Alloc>::template _iterator<T_it> old(*this);
		--(*this);
		return (old);
	}

	template<class T, class Alloc>
	template<class T_it>
	
	typename vector<T, Alloc>::template _iterator<T_it>
		vector<T, Alloc>::template _iterator<T_it>::operator+(
			typename vector<T, Alloc>::template _iterator<T_it>::difference_type n
			) const
	{
		return _iterator(this->ptr + n);
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::template _iterator<T_it>
		vector<T, Alloc>::template _iterator<T_it>::operator-(
			vector<T, Alloc>::template _iterator<T_it>::difference_type n
			) const
	{
		return _iterator(this->ptr - n);
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::template _iterator<T_it>::difference_type
		vector<T, Alloc>::template _iterator<T_it>::operator-(
			const typename vector<T, Alloc>::template _iterator<T_it> &rhs
			) const
	{
		return (this->ptr - rhs.ptr);
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::template _iterator<T_it> &vector<T, Alloc>::template _iterator<T_it>::operator+=(
		vector<T, Alloc>::template _iterator<T_it>::difference_type n
		)
	{
		this->ptr += n;
		return *this;
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::template _iterator<T_it> &vector<T, Alloc>::template _iterator<T_it>::operator-=(
		vector<T, Alloc>::template _iterator<T_it>::difference_type n
		)
	{
		this->ptr -= n;
		return *this;
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	/************************** DEREFERENCE OPERATORS *************************/

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::template _iterator<T_it>::value_type
		&vector<T, Alloc>::template _iterator<T_it>::operator*(void) const
	{
		return *(this->ptr);
	}

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::template _iterator<T_it>::pointer
		vector<T, Alloc>::template _iterator<T_it>::operator->(void) const
	{
		return (this->ptr);
	}

	template<class T, class Alloc>
	template<class T_it>
	typename vector<T, Alloc>::template _iterator<T_it>::reference
		vector<T, Alloc>::template _iterator<T_it>::operator[](
			vector<T, Alloc>::template _iterator<T_it>::difference_type n
			) const
	{
		return (this->ptr[n]);
	}
}