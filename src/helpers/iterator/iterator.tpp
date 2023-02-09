/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:30:43 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/09 13:42:52 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{

	/******************** CONSTRUCTORS & DESTRUCTORS **************************/

	template<class T_it>
	iterator<T_it>::iterator(void)
	{
		this->ptr = nullptr;
	}

	template<class T_it>
	iterator<T_it>::iterator(const iterator<T_it> &rht)
	{
		*this = rht;
	}

	template<class T_it>
	iterator<T_it>::iterator(iterator<T_it>::pointer ptr)
	{
		this->ptr = ptr;
	}

	template<class T_it>
	iterator<T_it>::~iterator(void)
	{
		this->ptr = nullptr;
	}

	/************************** ASSIGNATION OPERATORS *************************/

	template<class T_it>
	iterator<T_it> &iterator<T_it>::operator=(
		const iterator<T_it> &rht
		)
	{
		this->ptr = rht.ptr;
		return (*this);
	}

	/*************************** ARITHMETIC OPERATORS *************************/

	template<class T_it>
	iterator<T_it>
		&iterator<T_it>::operator++(void)
	{
		this->ptr++;
		return *this;
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	template<class T_it>
	iterator<T_it> &iterator<T_it>::operator--(void)
	{
		this->ptr--;
		return *this;
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	template<class T_it>
	iterator<T_it> iterator<T_it>::operator++(int)
	{
		iterator<T_it> old(*this);
		++(*this);
		return (old);
	}

	template<class T_it>
	iterator<T_it> iterator<T_it>::operator--(int)
	{
		iterator<T_it> old(*this);
		--(*this);
		return (old);
	}

	template<class T_it>
	iterator<T_it>
		iterator<T_it>::operator+(
			iterator<T_it>::difference_type n
			) const
	{
		return iterator(this->ptr + n);
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	template<class T_it>
	iterator<T_it>
		iterator<T_it>::operator-(
			iterator<T_it>::difference_type n
			) const
	{
		return iterator(this->ptr - n);
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	template<class T_it>
	typename iterator<T_it>::difference_type
		iterator<T_it>::operator-(
			const iterator<T_it> &rhs
			) const
	{
		return (this->ptr - rhs.ptr);
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	template<class T_it>
	iterator<T_it> &iterator<T_it>::operator+=(
		iterator<T_it>::difference_type n
		)
	{
		this->ptr += n;
		return *this;
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	template<class T_it>
	iterator<T_it> &iterator<T_it>::operator-=(
		iterator<T_it>::difference_type n
		)
	{
		this->ptr -= n;
		return *this;
		//NOTE: if we implement non-contigus dark magic, we should do stuff with that here
	}

	/************************** DEREFERENCE OPERATORS *************************/

	template<class T_it>
	typename iterator<T_it>::value_type
		&iterator<T_it>::operator*(void) const
	{
		return *(this->ptr);
	}

	template<class T_it>
	typename iterator<T_it>::pointer
		iterator<T_it>::operator->(void) const
	{
		return (this->ptr);
	}

	template<class T_it>
	typename iterator<T_it>::reference
		iterator<T_it>::operator[](
			iterator<T_it>::difference_type n
			) const
	{
		return (this->ptr[n]);
	}

	/************************ EXTERNAL ARITHMETIC OPERATORS *******************/

	template<class T_it>
	iterator<T_it>
		operator+(
			typename  iterator<T_it>::difference_type n,
			const iterator<T_it> &it
			)
	{
		return (it + n);
	}
}