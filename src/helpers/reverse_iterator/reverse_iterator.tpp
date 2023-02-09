/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:27:08 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/08 14:55:20 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
/********************** CONSTRUCTORS & DESTRUCTORS ****************************/
	template<class It>
	reverse_iterator<It>::reverse_iterator(void)
	{
		it = iterator_type();
	}

	template<class It>
	reverse_iterator<It>::reverse_iterator(
		typename reverse_iterator<It>::iterator_type it
		)
	{
		this->it = it;
	}

	template<class It>
	template<class Iter>
	reverse_iterator<It>::reverse_iterator(
		const typename ft::reverse_iterator<Iter> &rhs
		)
	{
		this->it = iterator_type(rhs.it);
	}
	
	/**************************** ACCESSORS ***********************************/

	template<class It>
	typename reverse_iterator<It>::iterator_type
		reverse_iterator<It>::base(void)	const
	{
		return iterator_type(it + 1); //TODO: test
	}

	/************************ ARITHMETIC OPERATORS ****************************/

	template<class It>
	reverse_iterator<It>	&reverse_iterator<It>::operator++(void)
	{
		it--;
		return *this;
	}

	template<class It>
	reverse_iterator<It>	reverse_iterator<It>::operator++(int)
	{
		reverse_iterator<It> old(*this);
		++(*this);
		return old;
	}

	template<class It>
	reverse_iterator<It>	&reverse_iterator<It>::operator--(void)
	{
		it++;
		return *this;
	}

	template<class It>
	reverse_iterator<It>	reverse_iterator<It>::operator--(int)
	{
		reverse_iterator<It> old(*this);
		--(*this);
		return old;
	}

	template<class It>
	reverse_iterator<It>	&reverse_iterator<It>::operator+=(typename reverse_iterator<It>::difference_type n)
	{
		it -= n;
		return *this;
	}

	template<class It>
	reverse_iterator<It>	&reverse_iterator<It>::operator-=(typename reverse_iterator<It>::difference_type n)
	{
		it += n;
		return *this;
	}

	template<class It>
	reverse_iterator<It>	reverse_iterator<It>::operator+(
		typename reverse_iterator<It>::difference_type n
		)	const
	{
		return reverse_iterator(it - n);
	}

	template<class It>
	reverse_iterator<It>	reverse_iterator<It>::operator-(
		typename reverse_iterator<It>::difference_type n
		)	const
	{
		return reverse_iterator(it + n);
	}

	/*********************** DEREFERENCE OPERATORS ****************************/

	template<class It>
	typename reverse_iterator<It>::reference reverse_iterator<It>::operator*(void) const
	{
		return *--iterator_type(it); //maybe plutot it-- ou --it
	}

	template<class It>
	typename reverse_iterator<It>::pointer	reverse_iterator<It>::operator->(void) const
	{
		return &(operator*());
	}

	template<class It>
	typename reverse_iterator<It>::reference	reverse_iterator<It>::operator[](reverse_iterator<It>::difference_type n) const
	{
		return (base()[-n-1]);
	}

	/********************* EXTERNAL RELATIONNAL OPERATORS *********************/


	// template<class It>
	// bool	operator==(
	// 	const reverse_iterator<It> &lhs,
	// 	const reverse_iterator<It> &rhs
	// 	)


	// template<class It>
	// bool	operator!=(
	// 	const reverse_iterator<It> &lhs,
	// 	const reverse_iterator<It> &rhs
	// 	)


	// template<class It>
	// bool	operator<(
	// 	const reverse_iterator<It> &lhs,
	// 	const reverse_iterator<It> &rhs
	// 	)


	// template<class It>
	// bool	operator<=(
	// 	const reverse_iterator<It> &lhs,
	// 	const reverse_iterator<It> &rhs
	// 	)


	// template<class It>
	// bool	operator>(
	// 	const reverse_iterator<It> &lhs,
	// 	const reverse_iterator<It> &rhs
	// 	)


	// template<class It>
	// bool	operator>=(
	// 	const reverse_iterator<It> &lhs,
	// 	const reverse_iterator<It> &rhs
	// 	)


	/********************* EXTERNAL ARITHMETIC OPERATORS **********************/

	template<class It>
	reverse_iterator<It>	operator+(
		typename reverse_iterator<It>::difference_type n,
		const reverse_iterator<It> &rhs
		)
	{
		return reverse_iterator<It>(rhs.it - n);
	}

	template<class It>
	typename reverse_iterator<It>::difference_type	operator-(
		const reverse_iterator<It> &lhs,
		const reverse_iterator<It> &rhs
		)
	{
		return rhs.it - lhs.it;
	}
}


