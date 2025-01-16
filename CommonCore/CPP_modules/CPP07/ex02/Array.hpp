/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:19:41 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/16 15:27:53 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
	#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T t;
	public: 
		Array();
		Array(unsigned int n);
		Array(const Array &orig);
		Array operator=(const Array &orig);
		~Array();
		
	std::ostream &operator[](std::ostream &os, const Array &obj);
	unsigned int size(T *array);
};


#endif