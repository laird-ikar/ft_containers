/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:34:18 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/17 16:32:22 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>

#include "../../helpers/reverse_iterator/reverse_iterator.tpp"

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
	class map
	{	
		public:
            typedef Key													key_type;
            typedef T													mapped_type;
            typedef std::pair<const Key,T>								value_type;
            typedef Compare												key_compare;
            typedef value_compare<value_type>							value_compare;
            typedef Alloc												allocator_type;
            typedef typename allocator_type::reference					reference;
            typedef typename allocator_type::const_reference			const_reference;
            typedef typename allocator_type::pointer					pointer;
            typedef typename allocator_type::const_pointer				const_pointer;
            typedef ft::bidirectionnal_iterator<value_type>				iterator;
            typedef ft::bidirectionnal_iterator<const value_type>		const_iterator;
            typedef ft::reverse_iterator<iterator>						reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
            typedef ptrdiff_t											difference_type;
            typedef size_t												size_type;

		private:
			value_type	*data;
			size_type	size;
			size_type	allocated_size;
			
		public:
			
            /**
			 *	@brief	Constructs an empty container, with no elements.
			 *	@param	alloc	allocator object, keeped and used by the map 
			 */
            explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

            /**
			 *	@brief	Constructs a container with as many elements as the range [first,last)
			 *	@param	first	Input iterator to the initial position in a range
			 *	@param	last	Input iterator to the final position in a range
			 *	@param	alloc	allocator object, keeped and used by the map
			 */
            template <class InputIterator>
            map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
            
            /**
			 *	@brief	Constructs a container with a copy of each of the elements in x, in the same order.
			 *	@param	x	A map object of the same type, whose contents are either copied or acquired.
			 */
			map(const map& x);

            /**
			 *	@brief	Destructor of the map
			 */
            ~map();

            /**
			 *	@brief	Replaces the contents with a copy of the contents of x
			 *	@param	x	The map to copy
			 *	@return	*this
			 */
            map& operator=(const map& x);

			/************************* ITERATORS *************************/
			
            /**	
			 *	@return	an iterator to the first element of the map
			 */
			iterator                begin();

            /**	
			 *	@return	a const iterator to the first element of the map
			 */
            const_iterator          begin() const;

            /**
			 *	@return an interator to the past-the-end element of the map
			 */
            iterator                end();

            /**
			 *	@return a const interator to the past-the-end element of the map
			 */
            const_iterator          end() const;

            /**
			 *	@return	a reverse iterator to the reverse first element of the map (i.e. the last element)
			 */
            reverse_iterator        rbegin();

            /**
			 *	@return	a const reverse iterator to the reverse first element of the map (i.e. the last element)
			 */
            const_reverse_iterator  rbegin() const;

            /**
			 *	@return	a reverse iterator to the reverse past-the-end element of the map (i.e. the theoretical element preceding the first element)
			 */
            reverse_iterator        rend();

            /**
			 *	@return	a const reverse iterator to the reverse past-the-end element of the map (i.e. the theoretical element preceding the first element)
			 */
            const_reverse_iterator  rend() const;
			
			/************************* CAPACITY *************************/

            /**
			 *	@return whether the map is empty (i.e. size == 0) 
			 */
            bool        empty() const;

            /**
			 * 	@return the number of elements in the map
			 */
            size_type   size() const;

            /**
			 * 	@return the maximum of elements the map can hold
			 */
            size_type   max_size() const;
            

			/************************* ELEMENT ACCESS *************************/

            /**
			 *	@param	k	Key value of the element to search for
			 *	@return	Reference to the mapped value of the element with key value k
			 *  @note	If k does not match the key of any element in the container, the function inserts a new element with that key and returns a reference to its mapped value (this always increases the container size by one)
			 */
            mapped_type& operator[](const key_type& k);
            
		    
			/************************* MODIFIERS *************************/
			
            /**
			 *	@brief	Extends the container by inserting a new element (and increase the container size by one)
			 *	@param	val	Value to be copied (or moved) to the inserted elements
			 *	@return	A pair, with its member pair::first set to an iterator pointing to either the newly inserted element or to the element with an equivalent key in the map.
			 		The pair::second element in the pair is set to true if a new element was inserted or false if an equivalent key already existed.
			 */
            std::pair<iterator,bool>    insert(const value_type& val);

            /**
			 *	@brief	Extends the container by inserting new elements (and increase the container size by the number of elements inserted)
			 *	@param	position	Position in the container where the new elements are inserted
			 *	@param	val			Value to be copied (or moved) to the inserted elements
			 *	@return	An iterator that points to the first of the newly inserted elements.
			 */
            iterator                    insert(iterator position, const value_type& val);

            /**
			 *	@brief	Extends the container by inserting new elements (and increase the container size by the number of elements inserted)
			 *	@param	first	Input iterator to the initial position in a range
			 *	@param	last	Input iterator to the final position in a range
			 */
            template <class InputIterator>
            void                        insert(InputIterator first, InputIterator last);

            /**
			 *	@brief	Removes from the map container a single element
			 *	@param	position	Iterator pointing to the element to be removed from the map
			 */
            void                        erase(iterator position);

            /**
			 *	@brief	Removes from the map container a single element
			 *	@param	k	Key value of the element to be removed from the map
			 *	@return	1 or 0, depending on whether the element was removed or not (i.e. if the map contained -or not- an element with the specified key)
			 */
            size_type                   erase(const key_type& k);

            /**
			 *	@brief	Removes from the map container a range of elements
			 *	@param	first	Input iterator to the initial position in a range
			 *	@param	last	Input iterator to the final position in a range
			 */
            void                        erase(iterator first, iterator last);

            /**
			 *	@brief	Exchanges the content of the container by the content of x. Sizes may differ.
			 *	@param	x	Another map of the same type as this, whose content is swapped with that of this map
			 */
            void                        swap(map& x);

            /**
			 *	@brief	Removes all elements from the map container (which are destroyed), leaving the container with a size of 0
			 */
            void                        clear();

            /************************* OBSERVERS *************************/

            /**
			 *	@return	A copy of the comparison object used by the container to compare keys
			 */
            key_compare     key_comp() const;

            /**
			 *	@return	A comparison object that can be used to compare two elements to get whether the key of the first one goes before the second
			 */
            value_compare   value_comp() const;

            /************************* OPERATIONS *************************/

            /**
			 *	@brief Searches the container for an element
			 *	@param	k	Key value of the element to search for
			 *	@return	An iterator to the element, if an element with specified key is found, or map::end otherwise
			 */
            iterator                                    find(const key_type& k);

            /**
			 *	@brief	Searches the container for an element
			 *	@param	k	Key value of the element to search for
			 *	@return	A const iterator to the element, if an element with specified key is found, or map::end otherwise
			 */
            const_iterator                              find(const key_type& k) const;

            /**
			 *	@brief	Counts the number of elements with a specific key
			 *	@param	k	Key value of the elements to count
			 *	@return	The number of elements with the specified key, which is either 1 or 0 since this container does not allow duplicates ¯\_(ツ)_/¯
			 */
            size_type                                   count(const key_type& k) const;

            /**
			 *	@param	k	Key value of the elements whose lower bound is returned
			 *	@return	An iterator pointing to the first element in the container whose key is not considered to go before k 
			 		(i.e., either it is equivalent or goes after)
			 */
            iterator                                    lower_bound(const key_type& k);

            /**
			 *	@param	k	Key value of the elements whose lower bound is returned
			 *	@return	A const iterator pointing to the first element in the container whose key is not considered to go before k 
			 		(i.e., either it is equivalent or goes after)
			 */
            const_iterator                              lower_bound(const key_type& k) const;

            /**
			 *	@param	k	Key value of the elements whose upper bound is returned
			 *	@return	An iterator pointing to the first element in the container whose key is not considered to go after k 
			 		(i.e., either it is equivalent or goes before)
			 */
            iterator                                    upper_bound(const key_type& k);

            /**
			 *	@param	k	Key value of the elements whose upper bound is returned
			 *	@return	A const iterator pointing to the first element in the container whose key is not considered to go after k 
			 		(i.e., either it is equivalent or goes before)
			 */
            const_iterator                              upper_bound(const key_type& k) const;

            /**
			 *	@param	k	Key value of the elements whose range of equivalent elements is returned
			 *	@return the bounds of a range that includes all the elements in the container which have a key equivalent to k. If no matches are found, 
			 		the range returned has a length of zero, with both const iterators pointing to the first element that has a key considered to go after k 
			 		according to the container's internal comparison object (key_comp)
					What if there isn't any element that goes after k? Well, then both const iterators will point to the end of the container ig ?
			 */
            std::pair<const_iterator,const_iterator>    equal_range(const key_type& k) const;

            /**
			 *	@param	k	Key value of the elements whose range of equivalent elements is returned
			 *	@return the bounds of a range that includes all the elements in the container which have a key equivalent to k. If no matches are found, 
			 		the range returned has a length of zero, with both iterators pointing to the first element that has a key considered to go after k 
			 		according to the container's internal comparison object (key_comp)
					What if there isn't any element that goes after k? Well, then both iterators will point to the end of the container ig ?
			 */
            std::pair<iterator,iterator>                equal_range(const key_type& k);
			
			/************************* ALLOCATOR *************************/

            /**
			 *	@return The allocator object used by the map
			 */
            allocator_type get_allocator() const;
    };

	/**
	 * @param lhs	the left term of the comparaison
	 * @param rhs	the right term of the comparaison
	 * @return the comparaison == between lhs and rhs
	 */
	template <class Key, class T, class Compare, class Alloc>
	bool operator== (const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs);

	/**
	 * @param lhs	the left term of the comparaison
	 * @param rhs	the right term of the comparaison
	 * @return the comparaison != between lhs and rhs
	 */
	template <class Key, class T, class Compare, class Alloc>
	bool operator!= (const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs);

	/**
	 * @param lhs	the left term of the comparaison
	 * @param rhs	the right term of the comparaison
	 * @return the comparaison < between lhs and rhs
	 */
	template <class Key, class T, class Compare, class Alloc>
	bool operator< (const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs);

	/**
	 * @param lhs	the left term of the comparaison
	 * @param rhs	the right term of the comparaison
	 * @return the comparaison <= between lhs and rhs
	 */
	template <class Key, class T, class Compare, class Alloc>
	bool operator<= (const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs);

	/**
	 * @param lhs	the left term of the comparaison
	 * @param rhs	the right term of the comparaison
	 * @return the comparaison > between lhs and rhs
	 */
	template <class Key, class T, class Compare, class Alloc>
	bool operator> (const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs);

	/**
	 * @param lhs	the left term of the comparaison
	 * @param rhs	the right term of the comparaison
	 * @return the comparaison >= between lhs and rhs
	 */
	template <class Key, class T, class Compare, class Alloc>
	bool operator>= (const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs);

	/**
	 * @brief exchange the content of the maps x and y
	 * @note both maps must have the same type
	 * @param x the element to swap with y
	 * @param y	the element to swap with x
	 */
	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y);
};

#include "map.tpp"
#include "map_iterator.hpp"