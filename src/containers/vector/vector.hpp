/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:34:18 by bguyot            #+#    #+#             */
/*   Updated: 2023/01/31 14:31:11 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	VECTOR_HPP
#define VECTOR_HPP

#include <memory>

// #include "../../helpers/random_access_iterator/random_access_iterator.tpp" //g envie dcrever rien qu'davoir a ecrire ca
#include "../../helpers/reverse_iterator/reverse_iterator.tpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
		private:
			template<class T_it>
			class _iterator
			{
				public:
					typedef	std::random_access_iterator_tag	category;
					typedef	T_it							value_type;
					typedef	long long int					difference_type;
					typedef	T_it*							pointer;
					typedef	T_it&							reference;
				
				private:
					pointer ptr;
			};

		public:
			typedef	T														value_type;
			typedef	Allocator												allocator_type;
			typedef	typename allocator_type::reference						reference;
			typedef	typename allocator_type::const_reference				const_reference;
			typedef	typename allocator_type::pointer						pointer;
			typedef	typename allocator_type::const_pointer					const_pointer;
			typedef	_iterator<value_type>									iterator;
			typedef	_iterator<const value_type>								const_iterator;
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef	typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef	size_t													size_type;

		private:
			value_type	*data;
			size_type	size;
			size_type	allocated_size;
			
		public:
			/**
			 *	@brief	Constructs an empty vector with no elements
			 *	@param	alloc	allocator object, keeped and used by the vector
			 */
			vector(const allocator_type &alloc = allocator_type());

			/**
			 *	@brief	Constructs a vector of size n filled with copy of val
			 *	@param	n		initial vector size 
			 *	@param	val		value to fill the container with
			 *	@param	alloc	allocator object, keeped and used by the vector
			 */
			vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type());
			
			/**
			 *	@brief	Constructs a vector which contents is a copy of the range [first, last)
			 *	@t
			 *	@param	first	the start of the range to copy
			 *	@param	last	the end of the range to copy (will not be copied)
			 *	@param	alloc	Allocator object, keeped and used by the vector
			 */
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());

			/**
			 *	@brief	Constructs a new vector which is a copy of x
			 *	@param	x	the vector to copy
			 */
			vector(const vector& x);

			/**
			 *	@brief	Destructor of the vector
			 */
			virtual ~vector();

			/**
			 *	@brief	Replaces the contents with a copy of the contents of x
			 *	@param	x	The vector to copy
			 *	@return	*this
			 */
			vector	&operator=(const vector &x);

			/************************* ITERATORS *************************/
			
			/**	
			 *	@return	an iterator to the first element of the vector
			 */
			iterator	begin(void);

			/**
			 *	@return	a const iterator to the first element of the vector
			 */
			const_iterator	begin(void) const;

			/**
			 *	@return an interator to the past-the-end element of the vector
			 */
			iterator				end(void);

			/**
			 *	@return a const interator to the past-the-end element of the vector
			 */
			const_iterator			end(void) const;

			/**
			 *	@return	a reverse iterator to the reverse first element of the vector (i.e. the last element)
			 */
			reverse_iterator		rbegin(void);

			/**
			 *	@return	a const reverse iterator to the reverse first element of the vector (i.e. the last element)
			 */
			const_reverse_iterator	rbegin(void) const;

			/**
			 *	@return	a reverse iterator to the reverse past-the-end element of the vector (i.e. the theoretical element preceding the first element)
			 */
			reverse_iterator 		rend(void);

			/**
			 *	@return	a const reverse iterator to the reverse past-the-end element of the vector (i.e. the theoretical element preceding the first element)
			 */
			const_reverse_iterator	rend(void) const;
			
			/************************* CAPACITY *************************/

			/**
			 * 	@return the number of elements in the vector
			 */
			size_type			size(void) const;
		
			/**
			 * 	@return the potential maximum of elements the vector can hold
			 */
			size_type			max_size(void) const;

			/**
			 *	@brief	resize the vector so that it contains n elements
			 *	if n < current size, it reduce the content and removes those beyond (and destroys them) ;
			 *	if n > current size, it expand the content and insert as many copy of val as needed ;
			 *	if n also > capacity, a automatic reallocation takes place
			 *	@param	n	the new vector size, in number of elements
			 *	@param	val	object that is copied to fill the new elements (if not specified, it uses the default constructor of value_type)
			 */
			void				resize(size_type n, value_type val = value_type());
			
			/**
			 * 	@return the size the storage space allocated for the vector in term of elements (may defer from size())
			 */
			size_type			capacity(void) const;

			/**
			 *	@return whether the vector is empty (i.e. size == 0) 
			 */
			bool				empty(void) const;
			
			/**
			 *	@brief requests that the capacity be at least enought to contains n elements
			 *	and realocate if necessary
			 *	@param n	the minimum capacity requested
			 */
			void				reserve(size_type n);

			/************************* ELEMENT ACCESS *************************/

			/**
			 *	@param n	Position of the element to return
			 *  @return a reference to the element at position n in the vector.
			 */
			reference			operator[](size_type n);

			/**
			 *	@param n	Position of the element to return
			 *  @return a const reference to the element at position n in the vector.
			 */
			const_reference		operator[](size_type n) const;

			/**
			 *	@param n	Position of the element to return (but better than operator[] eheh)
			 *  @return a reference to the element at position n in the vector.
			 */
			reference			at(size_type n);

			/**
			 *	@param n	Position of the element to return (but better than operator[] eheh)
			 *  @return a const reference to the element at position n in the vector.
			 */
			const_reference		at(size_type n) const;

			/**
			 *  @return a reference to the first element in the vector.
					(Unlike member vector::begin, which returns an iterator to this same element, this function returns a direct reference.)
			 */
			reference			front(void);
			
			/**
			 *  @return a const reference to the first element in the vector.
					(Unlike member vector::begin, which returns a const iterator to this same element, this function returns a direct const reference.)
			 */
			const_reference		front(void) const;
			
			/**
			 *	@return a reference to the last element in the vector.
			 		(Unlike member vector::end, which returns an iterator just past this element, this function returns a direct reference.)
			 */
			reference			back(void);
			
			/**
			*	@return a const reference to the last element in the vector.
			 		(Unlike member vector::end, which returns a const iterator just past this element, this function returns a direct const reference.)
			 */
			const_reference		back(void) const;
		    
			/************************* MODIFIERS *************************/
			
			/**
			 *	@brief	Replace the contents with n copies of val
			 *	@param n	the number of copies to do
			 *	@param val	the value to copy
			 */
			void				assign(size_type n, const value_type &val);
			
			/**
			 *	@brief  Replace the contents with copies of those in the range [first, last)
			 *	@param	first	the start of the range to copy
			 *	@param	last	the end of the range to copy (will not be copied)
			 */
			template<InputIt>
			void				assign(InputIt first, InputIt last);

			/**
			 *	@brief Add an element to the end of the vector.
			 *	@param val	value to be copied to the new element.
			 */
			void				push_back(const value_type& val);
			
			/**
			 *	@brief Remove the last element of the vector.
			 */
			void				pop_back(void);

			/**
			 *	@brief Insert an element into the vector.
			 *	@param position	position in the vector where the new element are inserted.
			 *	@param val		value to be copied to the inserted elements.
			 */
			iterator			insert(iterator position, const value_type& val);

			/**
			 *	@brief Insert multiple copies of an element into the vector.
			 *	@param position	position in the vector where the new element are inserted.
			 *	@param n		number of elements (copies of val) to be inserted.
			 *	@param val		value to be copied to the inserted elements.
			 */
			void				insert(iterator position, size_type n, const value_type& val);
			
			/**
			 *	@brief Insert a range of elements into the vector.
			 *	@param position position in the vector where the new elements are inserted.
			 *	@param first	iterator specifying the first element in the range to be inserted.
			 *	@param last		iterator specifying the last element in the range to be inserted.
			 */
			template<class InputIterator>
			void				insert(iterator position, iterator first, iterator last);
			
			/**
			 *	@brief Removes from the vector either a single element
			 *	@param position	iterator pointing to the element to be removed from the vector.
			 */
			void				erase(iterator position);
			
			/**
			 *	@brief Removes a range of elements ([first,last)).
			 *	@param first	iterator specifying the first element to be removed from the vector.
			 *	@param last		iterator specifying the last element to be removed from the vector.
			 */
			void				erase(iterator first, iterator last);
			
			/**
			 *	@brief Exchanges the content of the container by the content of x, which is another vector object of the same type (sizes may differ)
			 *	@param x 	another vector container of the same type whose content is swapped with that of this container.
			 */
			void				swap(vector& x);
			
			/**
			 *	@brief Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
			 */
			void				clear(void);
			
			/************************* ALLOCATOR *************************/
			
			/**
			 *	@return A copy of the allocator object associated with the vector.
			 */
			allocator_type		get_allocator(void) const;
	};

	/**
	 * @param lhs	the left term of the comparaison
	 * @param rhs	the right term of the comparaison
	 * @return the comparaison == between lhs and rhs
	 */
	template <class T, class Alloc> 
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	/**
	 * @param lhs	the left term of the comparaison
	 * @param rhs	the right term of the comparaison
	 * @return the comparaison != between lhs and rhs
	 */
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	/**
	 * @param lhs	the left term of the comparaison
	 * @param rhs	the right term of the comparaison
	 * @return the comparaison < between lhs and rhs
	 */
	template <class T, class Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	/**
	 * @param lhs	the left term of the comparaison
	 * @param rhs	the right term of the comparaison
	 * @return the comparaison <= between lhs and rhs
	 */
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	/**
	 * @param lhs	the left term of the comparaison
	 * @param rhs	the right term of the comparaison
	 * @return the comparaison > between lhs and rhs
	 */
	template <class T, class Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	/**
	 * @param lhs	the left term of the comparaison
	 * @param rhs	the right term of the comparaison
	 * @return the comparaison >= between lhs and rhs
	 */
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	/**
	 * @brief exchange the content of the vectors x and y
	 * @note both vectors must have the same type
	 * @param x the element to swap with y
	 * @param y	the element to swap with x
	 */
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
};

#endif