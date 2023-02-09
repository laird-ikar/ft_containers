/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:58:07 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/09 13:42:52 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template<class T_it>
	class iterator
	{
		public:
				typedef	std::random_access_iterator_tag	iterator_category;
				typedef	T_it							value_type;
				typedef	long long int					difference_type;
				typedef	T_it*							pointer;
				typedef	T_it&							reference;
			
			private:
				pointer ptr;

			public:

			/****************** CONSTRUCTORS & DESTRUCTOR *****************/

				/**
				 * @brief	Constructs an iterator pointing on nullptr
				 */
				iterator(void);

				/**
				 * @brief	Constructs an iterator pointing on the same term as rht
				 * @param	rht	The iterator we are copying
				 */
				iterator(const iterator &rht);

				/**
				 * @brief	Create an iterator pointing on ptr
				 * @param	ptr	The pointer the iterator will point to
				 */
				iterator(pointer ptr);

				/**
				 * @brief	Destructs the iterator
				 */
				virtual ~iterator(void);

			/******************** ASSIGNATION OPERATORS *******************/

				/**
				 * @brief	Changes the address pointed by this so that it points the same as rht
				 * @param	rht	The iterator we are copying
				 * @return	*this
				 */ 
				iterator	&operator=(const iterator &rht);

			/********************* ARITHMETIC OPERATORS *******************/

				/**
				 * @brief	Pre-increment operator: make ptr points to the next (virtual) object in the vector
				 * @return	A reference to this, modified
				 */
				iterator	&operator++(void);

				/**
				 * @brief	Pre-decrement operator: make ptr points to the previous (virtual) object in the vector
				 * @return	A reference to this, modified
				 */
				iterator	&operator--(void);

				/**
				 * @brief	Post-increment operator: make ptr points to the next (virtual) object in the vector
				 * @return	A copy of this before it was modified
				 */
				iterator	operator++(int);

				/**
				 * @brief	Post-decrement operator: make ptr points to the previous (virtual) object in the vector
				 * @return	A copy of this before it was modified
				 */
				iterator	operator--(int);

				/**
				 * @brief	Addition operator (it + n): make ptr points to the nth next (virtual) object in the vector
				 * @param	n	The value to add to the pointer
				 * @return	A reference to this modified
				 */
				iterator	operator+(difference_type n) const;

				/**
				 * @brief	Substraction operator (it - n): make ptr points to the nth previous (virtual) object in the vector
				 * @param	n	The value to substract to the pointer
				 * @return	A reference to this modified
				 */
				iterator	operator-(difference_type n) const;

				/**
				 * @brief	Substraction operator (this - rhs): make ptr points to the nth previous (virtual) object in the vector
				 * @param	rhs	The iterator to substract to this
				 * @return	A reference to this modified
				 */
				difference_type	operator-(const iterator &rhs) const;

				/**
				 * @brief	Addition assignment operator (it += n): make ptr points to the nth next (virtual) object in the vector
				 * @param	n	The value to add to the pointer
				 * @return	A reference to this modified
				 */
				iterator	&operator+=(difference_type n);

				/**
				 * @brief	Substraction assignment operator (it -= n): make ptr points to the nth previous (virtual) object in the vector
				 * @param	n	The value to substract to the pointer
				 * @return	A reference to this modified
				 */
				iterator	&operator-=(difference_type n);

				/****************** DEREFERENCE OPERATORS *****************/

				/**
				 * @brief	Dereferencing operator
				 * @return	A reference to the object pointed by ptr
				 */
				reference	operator*(void) const;

				/**
				 * @brief	Arrow operator
				 * @return	A pointer to the object pointed by ptr
				 */
				pointer	operator->(void) const;

				/**
				 * @brief	Subscript operator
				 * @param	n	The index of the object we want to access
				 * @return	A reference to the object at index n
				 */
				reference	operator[](difference_type n) const;

			/*************** EXTERNAL RELATIONNAL OPERATORS ***************/

				/**
				 * @param lhs	the left term of the comparaison
				 * @param rhs	the right term of the comparaison
				 * @return the comparaison == between lhs and rhs
				 */
				friend bool	operator==(const iterator &lht, const iterator &rht)
				{
					return lht.ptr == rht.ptr;
				}

				/**
				 * @param lhs	the left term of the comparaison
				 * @param rhs	the right term of the comparaison
				 * @return the comparaison != between lhs and rhs
				 */
				friend bool	operator!=(const iterator &lht, const iterator &rht)
				{
					return !(lht == rht);
				}

				/*
					* @param lhs	the left term of the comparaison
					* @param rhs	the right term of the comparaison
					* @return the comparaison < between lhs and rhs
					*/
				friend bool	operator<(const iterator &lht, const iterator &rht)
				{
					return lht.ptr < rht.ptr;
				}

				/*
					* @param lhs	the left term of the comparaison
					* @param rhs	the right term of the comparaison
					* @return the comparaison <= between lhs and rhs
					*/
				friend bool	operator<=(const iterator &lht, const iterator &rht)
				{
					return lht.ptr <= rht.ptr;
				}

				/*
					* @param lhs	the left term of the comparaison
					* @param rhs	the right term of the comparaison
					* @return the comparaison > between lhs and rhs
					*/
				friend bool	operator>(const iterator &lht, const iterator &rht)
				{
					return lht.ptr > rht.ptr;
				}

				/*
					* @param lhs	the left term of the comparaison
					* @param rhs	the right term of the comparaison
					* @return the comparaison >= between lhs and rhs
					*/
				friend bool	operator>=(const iterator &lht, const iterator &rht)
				{
					return lht.ptr >= rht.ptr;
				}
	};

	/********************** EXTERNAL ARITHMETIC OPERATORS *********************/
				
	/**
	 * @brief	Addition operator (n + it): make ptr points to the nth next (virtual) object in the vector
	 * @return	A reference to the modified iterator
	 */
	template<class T_it>
	iterator<T_it> operator+(
		typename iterator<T_it>::difference_type n,
		const iterator<T_it> &it
		);
}

#include "iterator.tpp"
