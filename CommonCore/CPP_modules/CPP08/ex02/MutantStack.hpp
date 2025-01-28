/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:43:13 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/28 14:33:27 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
	#define MUTANTSTACK_HPP
	
#include <iostream>	
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack<T> &orig);
		MutantStack	&operator=(const MutantStack<T> &orig);
		~MutantStack();

	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const{ return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }

};

template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << "MutantStack constructor called" << std::endl;	
};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &orig) : std::stack<T>(orig)
{
	std::cout << "MutantStack copy constructor called" << std::endl;	
};

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &orig)
{
	if(this != &orig)
		std::stack<T>::operator=(orig);
	std::cout << "MutantStack copy operator called" << std::endl;
	return *this;
};

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack destructor called" << std::endl;	
};



#endif