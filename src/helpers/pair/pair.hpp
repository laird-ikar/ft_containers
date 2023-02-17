/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:45:57 by bguyot            #+#    #+#             */
/*   Updated: 2023/02/17 11:05:32 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{	
	template <class T1, class T2>
	class pair
	{
		public:
			typedef	T1	first_type;
			typedef	T2	second_type;

			first_type	first;
			second_type	second;

/********************************** CONSTRUCTORS ******************************/

			/**
			 * @brief	Default constructor
			 */
			pair(void);

			/**
			 * @brief	Copy constructor
			 * @tparam	U	Type of the first element
			 * @tparam	V	Type of the second element
			 * @param	pr	Source pair
			 */
			template <class U, class V>
			pair(const pair<U, V> &pr);

			/**
			 * @brief	Initialize constructor
			 * @param	a	First element
			 * @param	b	Second element
			 */
			pair(const first_type &a, const second_type &b);

/********************************* OPERATORS **********************************/

			/**
			 * @brief	Assignation operator
			 * @param	rhs	Source pair
			 * @return	Reference to the current pair
			 */
			pair &operator=(const pair &rhs);

/********************************** METHODS ***********************************/

			/**
			 * @brief	Swap the content of two pairs
			 * @param	pr	Source pair
			 */
			void swap(pair &pr);
	};
	
/*********************** EXTERNAL RELATIONNAL OPERATORS ***********************/

	/**
	 * @brief	Equal operator
	 * @tparam	T1	Type of the first element
	 * @tparam	T2	Type of the second element
	 * @param	lhs	First pair
	 * @param	rhs	Second pair
	 * @return	True if the two pairs are equal, false otherwise
	 */
	template <class T1, class T2>
	bool	operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);

	/**
	 * @brief	Different operator
	 * @tparam	T1	Type of the first element
	 * @tparam	T2	Type of the second element
	 * @param	lhs	First pair
	 * @param	rhs	Second pair
	 * @return	True if the two pairs are different, false otherwise
	 */
	template <class T1, class T2>
	bool	operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);

	/**
	 * @brief	Less than operator
	 * @tparam	T1	Type of the first element
	 * @tparam	T2	Type of the second element
	 * @param	lhs	First pair
	 * @param	rhs	Second pair
	 * @return	True if the first pair is less than the second one, false otherwise
	 */
	template <class T1, class T2>
	bool	operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);

	/**
	 * @brief	Greater than operator
	 * @tparam	T1	Type of the first element
	 * @tparam	T2	Type of the second element
	 * @param	lhs	First pair
	 * @param	rhs	Second pair
	 * @return	True if the first pair is greater than the second one, false otherwise
	 */
	template <class T1, class T2>
	bool	operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);

	/**
	 * @brief	Less than or equal operator
	 * @tparam	T1	Type of the first element
	 * @tparam	T2	Type of the second element
	 * @param	lhs	First pair
	 * @param	rhs	Second pair
	 * @return	True if the first pair is less than or equal to the second one, false otherwise
	 */
	template <class T1, class T2>
	bool	operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);

	/**
	 * @brief	Greater than or equal operator
	 * @tparam	T1	Type of the first element
	 * @tparam	T2	Type of the second element
	 * @param	lhs	First pair
	 * @param	rhs	Second pair
	 * @return	True if the first pair is greater than or equal to the second one, false otherwise
	 */
	template <class T1, class T2>
	bool	operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);

/****************************** EXTERNAL METHODS ******************************/

	/**
	 * @brief	Swap the content of two pairs
	 * @tparam	T1	Type of the first element
	 * @tparam	T2	Type of the second element
	 * @param	lhs	First pair
	 * @param	rhs	Second pair
	 */
	template <class T1, class T2>
	void	swap(pair<T1, T2> &lhs, pair<T1, T2> &rhs);

	/**
	 * @brief	
}