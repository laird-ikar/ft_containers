/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:54:48 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/07 17:11:118 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../iterator_traits/iterator_traits.hpp"
namespace ft
{
	/**
	 * @tparam	It	The iterator class we are to reverse
	*/
	template<class It>
	class reverse_iterator
	{
		public:
			typedef	It												iterator_type;
			typedef	typename iterator_traits<It>::iterator_category	iterator_category;
			typedef	typename iterator_traits<It>::value_type		value_type;
			typedef	typename iterator_traits<It>::difference_type	difference_type;
			typedef	typename iterator_traits<It>::pointer			pointer;
			typedef	typename iterator_traits<It>::reference			reference;
		
		private:
			iterator_type	it;

		public:

		/****************** CONSTRUCTORS & DESTRUCTORS ************************/

			/**
			 * @brief	default constructor
			 */
			reverse_iterator(void);
			
			/**
			 * @brief	initialisator constructor
			 * @param	it	the iterator we are using as a base
			 */
			explicit reverse_iterator(iterator_type it);

			/**
			 * @tparam	Iter	the iterator on which is based rhs
			 * @brief	copy constructor
			 * @param	rhs		the reverse_iterator to copy (preserving the sense of iteration)
			 */
			template<class Iter>
			reverse_iterator(const reverse_iterator<Iter> &rhs);

		/************************** ACCESSORS *********************************/

			/**
			 * @brief	Returns a copy of the base iterator
			 * @return	A copy of the base iterator, iterating in the opposing direction
			 */
			iterator_type	base(void)	const;
		
		/********************** ARITHMETIC OPERATORS **************************/

			/**
			 * @brief	Increments the reverse_iterator
			 * @return	A reference to the incremented reverse_iterator
			 */
			reverse_iterator	&operator++(void);

			/**
			 * @brief	Increments the reverse_iterator
			 * @return	A copy of the reverse_iterator before incrementation
			 */
			reverse_iterator	operator++(int);

			/**
			 * @brief	Decrements the reverse_iterator
			 * @return	A reference to the decremented reverse_iterator
			 */
			reverse_iterator	&operator--(void);

			/**
			 * @brief	Decrements the reverse_iterator
			 * @return	A copy of the reverse_iterator before decrementation
			 */
			reverse_iterator	operator--(int);

			/**
			 * @brief	Increments the reverse_iterator by n
			 * @param	n	the number of incrementations
			 * @return	A reference to the incremented reverse_iterator
			 */
			reverse_iterator	&operator+=(difference_type n);

			/**
			 * @brief	Decrements the reverse_iterator by n
			 * @param	n	the number of decrements
			 * @return	A reference to the decremented reverse_iterator
			 */
			reverse_iterator	&operator-=(difference_type n);
			
			/**
			 * @brief	Calculates the distance between two reverse_iterators
			 * @param	rhs	the second reverse_iterator
			 * @return	The distance between the two reverse_iterators
			 */
			template<class Iter>
			difference_type	operator-(const reverse_iterator<Iter> &rhs) const;

		/********************* DEREFERENCE OPERATORS **************************/

			/**
			 * @brief	Returns a reference to the element pointed by the base iterator
			 * @return	A reference to the element pointed by the base iterator
			 */
			reference	operator*(void)	const;

			/**
			 * @brief	Returns a pointer to the element pointed by the base iterator
			 * @return	A pointer to the element pointed by the base iterator
			 */
			pointer		operator->(void)	const;

			/**
			 * @brief	Returns a reference to the element pointed by the base iterator
			 * @param	n	the number of elements to jump
			 * @return	A reference to the element pointed by the base iterator
			 */
			reference	operator[](difference_type n)	const;

		/******************** EXTERNAL RELATIONNAL OPERATORS *******************/

			/**
			 * @brief	Compares two reverse_iterators
			 * @param	lhs	the first reverse_iterator
			 * @param	rhs	the second reverse_iterator
			 * @return	True if the base iterators are equal, false otherwise
			 */
			template<class Iter1, class Iter2>
			friend bool	operator==(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
			{
				return lhs.base() == rhs.base();
			}

			/**
			 * @brief	Compares two reverse_iterators
			 * @param	lhs	the first reverse_iterator
			 * @param	rhs	the second reverse_iterator
			 * @return	True if the base iterators are not equal, false otherwise
			 */
			template<class Iter1, class Iter2>
			friend bool	operator!=(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
			{
				return lhs.base() != rhs.base();
			}

			/**
			 * @brief	Compares two reverse_iterators
			 * @param	lhs	the first reverse_iterator
			 * @param	rhs	the second reverse_iterator
			 * @return	True if the base iterator of lhs is less than the base iterator of rhs, false otherwise
			 */
			template<class Iter1, class Iter2>
			friend bool	operator<(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
			{
				return lhs.base() > rhs.base();
			}

			/**
			 * @brief	Compares two reverse_iterators
			 * @param	lhs	the first reverse_iterator
			 * @param	rhs	the second reverse_iterator
			 * @return	True if the base iterator of lhs is less than or equal to the base iterator of rhs, false otherwise
			 */
			template<class Iter1, class Iter2>
			friend bool	operator<=(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
			{
				return lhs.base() >= rhs.base();
			}

			/**
			 * @brief	Compares two reverse_iterators
			 * @param	lhs	the first reverse_iterator
			 * @param	rhs	the second reverse_iterator
			 * @return	True if the base iterator of lhs is greater than the base iterator of rhs, false otherwise
			 */
			template<class Iter1, class Iter2>
			friend bool	operator>(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
			{
				return lhs.base() < rhs.base();
			}

			/**
			 * @brief	Compares two reverse_iterators
			 * @param	lhs	the first reverse_iterator
			 * @param	rhs	the second reverse_iterator
			 * @return	True if the base iterator of lhs is greater than or equal to the base iterator of rhs, false otherwise
			 */
			template<class Iter1, class Iter2>
			friend bool	operator>=(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
			{
				return lhs.base() <= rhs.base();
			}

		/********************** EXTERNAL ARITHMETIC OPERATORS *****************/

			/**
			 * @brief	Increments the reverse_iterator by n
			 * @param	lhs	the reverse_iterator
			 * @param	n	the number of incrementations
			 * @return	A copy of the incremented reverse_iterator
			 */
			friend reverse_iterator<It>	operator+(const reverse_iterator &lhs, difference_type n)
			{
				return reverse_iterator<It>(lhs.it - n);
			}

			/**
			 * @brief	Decrements the reverse_iterator by n
			 * @param	lhs	the reverse_iterator
			 * @param	n	the number of decrements
			 * @return	A copy of the decremented reverse_iterator
			 */
			friend reverse_iterator<It>	operator-(const reverse_iterator &lhs, difference_type n)
			{
				return reverse_iterator<It>(lhs.it + n);
			}

			/**
			 * @brief	Decrements the reverse_iterator by n
			 * @param	n	the number of decrements
			 * @param	rhs	the reverse_iterator
			 * @return	A copy of the decremented reverse_iterator
			 */
			friend reverse_iterator<It>	operator+(difference_type n, const reverse_iterator &lhs)
			{
				return reverse_iterator<It>(lhs.it - n);
			}
	};
}

#include "reverse_iterator.tpp"

