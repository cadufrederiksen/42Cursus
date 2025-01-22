/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:19:41 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/22 14:42:21 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
	#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int len;
	public: 
		Array();
		Array(unsigned int n);
		Array(const Array &orig);
		Array &operator=(const Array &orig);
		~Array();
		
	T &operator[](unsigned int index);
	unsigned int size();
};

template <typename T>
Array<T>::Array(){
	_array = new T[0];
	len = 0;
	std::cout << "Default Array constructor called" << std::endl;
};

template <typename T>
Array<T>::Array(unsigned int n){
	_array = new T[n];
	len = n;
	std::cout << "Array constructor called" << std::endl;
}

template <typename T>	
Array<T>::Array(const Array &orig){
	*this = orig;
	std::cout << "Array copy constructor called" << std::endl;
};

template <typename T>
Array<T>	&Array<T>::operator=(const Array &orig){
	if (this != &orig)
	{
		delete[] _array;
		len = orig.len;
		_array = new T[orig.len];
		for (int x = 0; x < orig.len; x++)
			this->_array[x] = orig._array[x];
	}
	std::cout << "Array copy operator called" << std::endl;
	return *this;
};

template <typename T>
Array<T>::~Array(){
	if (_array)
		delete[] _array;
	std::cout << "Array destuctor called" << std::endl;
};

template <typename T>
T &Array<T>::operator[](unsigned int index){
	if (index >= this->len)
		throw std::out_of_range("Index is out of the range");
	else 
		return _array[index];
};

template <typename T>
unsigned int Array<T>::size(){
	return len;
};

#endif