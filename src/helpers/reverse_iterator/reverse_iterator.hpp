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

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "../iterator_traits/iterator_traits.hpp"
#include "../iterator/iterator.hpp"

namespace ft
{
	/**
	 * @tparam	It	The iterator class we are to reverse
	*/
	template<class It>
	class reverse_iterator : public ft::iterator
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
			 * @brief	copy	constructor
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
			 * @brief	Increments the reverse_iterator by n
			 * @param	n	the number of incrementations
			 * @return	A copy of the incremented reverse_iterator
			 */
			reverse_iterator	operator+(difference_type n)	const;

			/**
			 * @brief	Decrements the reverse_iterator by n
			 * @param	n	the number of decrements
			 * @return	A copy of the decremented reverse_iterator
			 */
			reverse_iterator	operator-(difference_type n)	const;

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
	};

	/********************* EXTERNAL RELATIONNAL OPERATORS *********************/

	/**
	 * @tparam	It1	the iterator class of lhs
	 * @tparam	It2	the iterator class of rhs
	 * @brief	Compares two reverse_iterators
	 * @param	lhs	the first reverse_iterator
	 * @param	rhs	the second reverse_iterator
	 * @return	True if the base iterators are equal, false otherwise
	 */
	template<class It1, class It2>
	bool	operator==(const reverse_iterator<It1> &lhs, const reverse_iterator<It2> &rhs);

	/**
	 * @tparam	It1	the iterator class of lhs
	 * @tparam	It2	the iterator class of rhs
	 * @brief	Compares two reverse_iterators
	 * @param	lhs	the first reverse_iterator
	 * @param	rhs	the second reverse_iterator
	 * @return	True if the base iterators are not equal, false otherwise
	 */
	template<class It1, class It2>
	bool	operator!=(const reverse_iterator<It1> &lhs, const reverse_iterator<It2> &rhs);

	/**
	 * @tparam	It1	the iterator class of lhs
	 * @tparam	It2	the iterator class of rhs
	 * @brief	Compares two reverse_iterators
	 * @param	lhs	the first reverse_iterator
	 * @param	rhs	the second reverse_iterator
	 * @return	True if the base iterator of lhs is less than the base iterator of rhs, false otherwise
	 */
	template<class It1, class It2>
	bool	operator<(const reverse_iterator<It1> &lhs, const reverse_iterator<It2> &rhs);

	/**
	 * @tparam	It1	the iterator class of lhs
	 * @tparam	It2	the iterator class of rhs
	 * @brief	Compares two reverse_iterators
	 * @param	lhs	the first reverse_iterator
	 * @param	rhs	the second reverse_iterator
	 * @return	True if the base iterator of lhs is less than or equal to the base iterator of rhs, false otherwise
	 */
	template<class It1, class It2>
	bool	operator<=(const reverse_iterator<It1> &lhs, const reverse_iterator<It2> &rhs);

	/**
	 * @tparam	It1	the iterator class of lhs
	 * @tparam	It2	the iterator class of rhs
	 * @brief	Compares two reverse_iterators
	 * @param	lhs	the first reverse_iterator
	 * @param	rhs	the second reverse_iterator
	 * @return	True if the base iterator of lhs is greater than the base iterator of rhs, false otherwise
	 */
	template<class It1, class It2>
	bool	operator>(const reverse_iterator<It1> &lhs, const reverse_iterator<It2> &rhs);

	/**
	 * @tparam	It1	the iterator class of lhs
	 * @tparam	It2	the iterator class of rhs
	 * @brief	Compares two reverse_iterators
	 * @param	lhs	the first reverse_iterator
	 * @param	rhs	the second reverse_iterator
	 * @return	True if the base iterator of lhs is greater than or equal to the base iterator of rhs, false otherwise
	 */
	template<class It1, class It2>
	bool	operator>=(const reverse_iterator<It1> &lhs, const reverse_iterator<It2> &rhs);

	/**
	 * @tparam	It1	the iterator class of lhs
	 * @tparam	It2	the iterator class of rhs
	 * @brief	Compares two reverse_iterators
	 * @param	lhs	the first reverse_iterator
	 * @param	rhs	the second reverse_iterator
	 * @return	True if the base iterator of lhs is equal to the base iterator of rhs, false otherwise
	 */
	template<class It1, class It2>
	bool	operator==(const reverse_iterator<It1> &lhs, const It2 &rhs);

	/********************** EXTERNAL ARITHMETIC OPERATORS *********************/

	/**
	 * @tparam	It	the iterator class of lhs
	 * @tparam	D	the difference type of lhs
	 * @brief	Increments the reverse_iterator by n
	 * @param	lhs	the reverse_iterator
	 * @param	n	the number of incrementations
	 * @return	A copy of the incremented reverse_iterator
	 */
	template<class It, class D>
	reverse_iterator<It>	operator+(const reverse_iterator<It> &lhs, D n);

	/**
	 * @tparam	It	the iterator class of lhs
	 * @tparam	D	the difference type of lhs
	 * @brief	Decrements the reverse_iterator by n
	 * @param	lhs	the reverse_iterator
	 * @param	n	the number of decrements
	 * @return	A copy of the decremented reverse_iterator
	 */
	template<class It, class D>
	reverse_iterator<It>	operator-(const reverse_iterator<It> &lhs, D n);
}

#endif