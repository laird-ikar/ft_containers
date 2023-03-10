/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:47:39 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/17 16:32:46 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace ft
{
    template<class T, class Alloc>
    vector<T,Alloc>::vector(const typename vector<T,Alloc>::allocator_type &alloc)
    {
        this->_size = 0;
        this->_allocated_size = 0;
        this->_data = nullptr;
        this->_allocator = alloc;
    }

    template<class T, class Alloc>
    vector<T,Alloc>::vector(
        typename vector<T,Alloc>::size_type n,
        const typename vector<T,Alloc>::value_type &val,
        const typename vector<T,Alloc>::allocator_type &alloc
        )
    {
        this->_size = n;
        this->_allocated_size = n;
        this->_allocator = alloc;
        this->_data = this->_allocator.allocate(n);
        for (size_type i = 0; i < n; i++)
            this->_allocator.construct(this->_data + i, val);
    }

    template<class T, class Alloc>
    template<class InputIterator>
    void vector<T, Alloc>::do_construct(
        InputIterator first,
        InputIterator last,
        std::input_iterator_tag
        )
    {
        size_type size = ft::distance(first, last);;
        _allocated_size = 0;
        _size = 0;
        reserve(size);
        for (size_type i = 0; i < size; i++)
            _allocator.construct(_data + i, *first++);
        _size = size;
    }

    template<class T, class Alloc>
    template<class InputIterator>
    void vector<T, Alloc>::do_construct(
        InputIterator first,
        InputIterator last,
        std::random_access_iterator_tag
        )
    {
        size_type size = ft::distance(first, last);;
        _allocated_size = 0;
        _size = 0;
        reserve(size);
        std::memmove(_data, &(*first), size * sizeof(value_type));
        _size = size;
    }

	template<class T, class Alloc>
    template<class InputIterator>
    vector<T, Alloc>::vector(
        InputIterator first,
        InputIterator last,
        const typename vector<T,Alloc>::allocator_type &alloc,
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type*
        )
    {
        _allocator = alloc;
        do_construct(first, last, typename ft::iterator_traits<InputIterator>::iterator_category());
    }


    template<class T, class Alloc>
    vector<T,Alloc>::vector(const vector<T,Alloc> &x)
    {
        this->_size = 0;
        this->_allocated_size = 0;
        this->_data = nullptr;
        *this = x;
    }

    template<class T, class Alloc>
    vector<T,Alloc>::~vector()
    {
        for (size_type i = 0; i < this->_size; i++)
            this->_allocator.destroy(this->_data + i);
        this->_allocator.deallocate(this->_data, this->_allocated_size);
    }

    template<class T, class Alloc>
    vector<T,Alloc> &vector<T,Alloc>::operator=(const vector<T,Alloc> &x)
    {
        if (this != &x)
        {
            // delete old data
            for (size_type i = 0; i < this->_size; i++)
                this->_allocator.destroy(this->_data + i);
            this->_allocator.deallocate(this->_data, this->_allocated_size);
            
            //copy new data
            this->_size = x._size;
            this->_allocator = x._allocator; //doubt ?
            this->_allocated_size = x._allocated_size;
            this->_data = this->_allocator.allocate(x._allocated_size);
            for (size_type i = 0; i < x._size; i++)
                this->_allocator.construct(this->_data + i, x._data[i]);            
        }
        return (*this);
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::iterator vector<T,Alloc>::begin()
    {
        return iterator(this->_data);
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::const_iterator vector<T,Alloc>::begin() const
    {
        return const_iterator(this->_data);
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::iterator vector<T,Alloc>::end()
    {
        return iterator(this->_data + this->_size);
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::const_iterator vector<T,Alloc>::end() const
    {
        return const_iterator(this->_data + this->_size);
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::reverse_iterator vector<T,Alloc>::rbegin()
    {
        return (reverse_iterator(this->_data + this->_size));
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::const_reverse_iterator vector<T,Alloc>::rbegin() const
    {
        return (const_reverse_iterator(this->_data + this->_size));
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::reverse_iterator vector<T,Alloc>::rend()
    {
        return (reverse_iterator(this->_data));
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::const_reverse_iterator vector<T,Alloc>::rend() const
    {
        return (const_reverse_iterator(this->_data));
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::size_type vector<T,Alloc>::size() const
    {
        return (this->_size);
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::size_type vector<T,Alloc>::max_size() const
    {
        return (this->_allocator.max_size());
    }

    template<class T, class Alloc>
    void    vector<T,Alloc>::resize(typename vector<T,Alloc>::size_type n, typename vector<T,Alloc>::value_type val)
    {
        if (n > this->_size)
        {
            if (n > this->_allocated_size)
                this->reserve(n);
            for (size_type i = this->_size; i < n; i++)
                this->_allocator.construct(this->_data + i, val);
        }
        else if (n < this->_size)
        {
            for (size_type i = n; i < this->_size; i++)
                this->_allocator.destroy(this->_data + i);
        }
        this->_size = n;
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::size_type vector<T,Alloc>::capacity() const
    {
        return (this->_allocated_size);
    }

    template<class T, class Alloc>
    bool    vector<T,Alloc>::empty() const
    {
        return (this->_size == 0);
    }

    template<class T, class Alloc>
    void    vector<T,Alloc>::reserve(typename vector<T,Alloc>::size_type n)
    {        
        if (_allocated_size >= n || n > max_size())
            return ;
        size_type   to_alloc = 2;
        while (to_alloc < n)
        {
            to_alloc *= 2;
        }
        value_type *tmp = _allocator.allocate(to_alloc);
        for (size_type i = 0 ; i < _size ; i++)
        {
            _allocator.construct(tmp + i, _data[i]);
            _allocator.destroy(_data + i);
        }
        if (_allocated_size)
            _allocator.deallocate(_data, _allocated_size);
        _data = tmp;
        _allocated_size = to_alloc;
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::reference vector<T,Alloc>::operator[](typename vector<T,Alloc>::size_type n)
    {
        return (this->_data[n]);
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::const_reference vector<T,Alloc>::operator[](typename vector<T,Alloc>::size_type n) const
    {
        return (this->_data[n]);
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::reference vector<T,Alloc>::at(typename vector<T,Alloc>::size_type n)
    {
        if (n >= this->_size)
            throw std::out_of_range("ft::vector::at");
        return (this->_data[n]);
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::const_reference vector<T,Alloc>::at(typename vector<T,Alloc>::size_type n) const
    {
        if (n >= this->_size)
            throw std::out_of_range("ft::vector::at const");
        return (this->_data[n]);
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::reference vector<T,Alloc>::front()
    {
        return (this->_data[0]);
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::const_reference vector<T,Alloc>::front() const
    {
        return (this->_data[0]);
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::reference vector<T,Alloc>::back()
    {
        return (this->_data[this->_size - 1]);
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::const_reference vector<T,Alloc>::back() const
    {
        return (this->_data[this->_size - 1]);
    }

    template <class T, class Alloc>
    void   vector<T,Alloc>::assign(typename vector<T,Alloc>::size_type n, const typename vector<T,Alloc>::value_type &val)
    {
        this->clear();
        if (n > this->_allocated_size)
            this->reserve(n);
        for (size_type i = 0; i < n; i++)
            this->_allocator.construct(this->_data + i, val);
        this->_size = n;
    }


    template <class T, class Alloc>
    template <class InputIterator>
    void   vector<T,Alloc>::do_assign(
        InputIterator first,
        InputIterator last,
        std::input_iterator_tag)
    {
        this->clear();
        size_type n = ft::distance(first, last);
        if (n > this->_allocated_size)
            this->reserve(n);
        size_type i = -1;
        while(++i < n)
            this->_allocator.construct(this->_data + i, *first++);
        this->_size = n;
    }

    template <class T, class Alloc>
    template <class InputIterator>
    void   vector<T,Alloc>::do_assign(
        InputIterator first,
        InputIterator last,
        std::random_access_iterator_tag)
    {
        this->clear();
        size_type n = ft::distance(first, last);
        if (n > this->_allocated_size)
            this->reserve(n);
        std::memmove(this->_data, &(*first), n * sizeof(value_type));
        this->_size = n;
    }

    template <class T, class Alloc>
    template <class InputIterator>
    void   vector<T,Alloc>::assign(
        InputIterator first,
        InputIterator last,
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type*)
    {
        do_assign(first, last, typename ft::iterator_traits<InputIterator>::iterator_category());
    }

    template<class T, class Alloc>
    void    vector<T,Alloc>::push_back(const typename vector<T,Alloc>::value_type &val)
    {
        if (this->_size == this->_allocated_size)
            this->reserve(this->_size + 1);
        this->_allocator.construct(this->_data + this->_size, val);
        this->_size++;
    }

    template<class T, class Alloc>
    void    vector<T,Alloc>::pop_back()
    {
        this->_allocator.destroy(this->_data + this->_size - 1);
        this->_size--;
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::iterator vector<T,Alloc>::insert(
        typename vector<T,Alloc>::iterator position,
        const typename vector<T,Alloc>::value_type &val
        )
    {
        size_type pos = position - this->begin();
        this->reserve(this->_size + 1);
        std::memmove(
                &(*((begin() + pos) + 1)),
                &(*(begin() + pos)),
                (this->end() - (begin() + pos)) * sizeof(value_type)
            );
        *(begin() + pos) = val;
        this->_size++;
        return ((begin() + pos));
    }

    template<class T, class Alloc>
    void    vector<T,Alloc>::insert(
        typename vector<T,Alloc>::iterator position,
        typename vector<T,Alloc>::size_type n,
        const typename vector<T,Alloc>::value_type &val
        )
    {
        size_type pos = position - this->begin();
        this->reserve(this->_size + n);
        std::memmove(
                &(*(begin() + pos + n)),
                &(*(begin() + pos)),
                (end() - (begin() + pos)) * sizeof(value_type)
            );
        for (size_type i = 0; i < n; i++)
            *(begin() + pos + i) = val;
        this->_size += n;
    }
    
    template<class T, class Alloc>
    template<class InputIterator>
    void    vector<T,Alloc>::insert(
        typename vector<T,Alloc>::iterator position,
        InputIterator first,
        InputIterator last,
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type*
        )
    {
		size_type n = 0;
		for (InputIterator it = first ; it != last ; it++)
			n++;
        size_type pos = position - this->begin();
        this->reserve(this->_size + n);
        std::memmove(
                &(*(begin() + pos + n)),
                &(*(begin() + pos)),
                (end() - (begin() + pos)) * sizeof(value_type)
            );
        for (size_type i = 0; i < n; i++)
            *(begin() + pos + i) = *first++;
        this->_size += n;
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::iterator vector<T,Alloc>::erase(
        typename vector<T,Alloc>::iterator position
        )
    {
        std::memmove(
                &(*position),
                &(*(position + 1)),
                (this->end() - position) * sizeof(value_type)
            );
        if (std::is_trivially_destructible<value_type>::value == false)
            this->_allocator.destroy(this->_data + this->_size - 1);
        this->_size--;
        return (position);
    }

    template<class T, class Alloc>
    typename vector<T,Alloc>::iterator vector<T,Alloc>::erase(
        typename vector<T,Alloc>::iterator first,
        typename vector<T,Alloc>::iterator last
        )
    {
        size_type n = std::distance(first, last);
        std::memmove(
                &(*first),
                &(*(first + n)),
                (this->end() - first) * sizeof(value_type)
            );
        if (std::is_trivially_destructible<value_type>::value == false)
            for (size_type i = 0; i < n; i++)
                this->_allocator.destroy(this->_data + this->_size - 1 - i);
        this->_size -= n;
        return (first);
    }

    template<class T, class Alloc>
    void    vector<T,Alloc>::swap(vector<T,Alloc> &x)
    {
        ft::swap(this->_data, x._data);
        ft::swap(this->_size, x._size);
        ft::swap(this->_allocated_size, x._allocated_size);
        ft::swap(this->_allocator, x._allocator);
    }

    template<class T, class Alloc>
    void    vector<T,Alloc>::clear(void)
    {
        if (!std::is_trivially_destructible<value_type>::value)
            for (size_type i = this->_size; i ; i--)
                this->_allocator.destroy(this->_data + i - 1);
        this->_size = 0;
    }
    

    template<class T, class Alloc>
    typename vector<T,Alloc>::allocator_type vector<T,Alloc>::get_allocator() const
    {
        return (this->_allocator);
    }

    template<class T, class Alloc>
    bool   operator==(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        for (size_t i = 0; i < lhs.size(); i++)
        {
            if (lhs[i] != rhs[i])
                return (false);
        }
        return (true);
    }

    template<class T, class Alloc>
    bool   operator!=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
    {
        return (!(lhs == rhs));
    }

    template<class T, class Alloc>
    bool   operator<(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
    {
        size_t i = 0;
        while (i < lhs.size() && i < rhs.size())
        {
            if (lhs[i] < rhs[i])
                return (true);
            else if (lhs[i] > rhs[i])
                return (false);
            i++;
        }
        if (i == lhs.size() && i != rhs.size())
            return (true);
        return (false);
    }

    template<class T, class Alloc>
    bool   operator<=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
    {
        return (!(rhs < lhs));
    }

    template<class T, class Alloc>
    bool   operator>(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
    {
        return (rhs < lhs);
    }

    template<class T, class Alloc>
    bool   operator>=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
    {
        return (!(lhs < rhs));
    }

    template<class T, class Alloc>
    void   swap(vector<T,Alloc> &x, vector<T,Alloc> &y)
    {
        x.swap(y);
    }
}
