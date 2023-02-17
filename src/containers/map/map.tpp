/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:45:46 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/17 16:37:53 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace ft
{
    //map constructors
    template <class Key, class T, class Compare, class Alloc>
    map<Key, T, Compare, Alloc>::map(const key_compare &comp, const allocator_type &alloc)
    {
        this->_comp = comp;
        this->_alloc = alloc;
        this->_size = 0;
        this->_allocated_size = 0;
        this->_root = NULL;
        this->_data = NULL;
    }

    template <class Key, class T, class Compare, class Alloc>
    template <class InputIterator>
    map<Key, T, Compare, Alloc>::map(
        InputIterator first,
        InputIterator last,
        const key_compare &comp, const allocator_type &alloc)
    {
        this->_comp = comp;
        this->_alloc = alloc;
        this->_size = 0;
        this->_allocated_size = 0;
        this->_root = NULL;
        this->_data = NULL;
        insert(first, last);
    }

    template <class Key, class T, class Compare, class Alloc>
    map<Key, T, Compare, Alloc>::map(const map &x)
    {
        this = x;
    }

    //map destructor
    template <class Key, class T, class Compare, class Alloc>
    map<Key, T, Compare, Alloc>::~map()
    {
        clear();
    }
}