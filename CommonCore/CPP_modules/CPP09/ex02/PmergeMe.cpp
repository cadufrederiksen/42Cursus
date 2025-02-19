/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:19:01 by carmarqu          #+#    #+#             */
/*   Updated: 2025/02/11 12:06:18 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &orig)
{
	if (this != &orig)
	{
		_vector = orig._vector;
		_list = orig._list;
	}
	std::cout << "PmergeMe copy operator called" << std::endl;
	return *this;
}

PmergeMe::PmergeMe(const PmergeMe &orig)
{
	*this = orig;
	std::cout << "PmergeMe copy construcotr called" << std::endl;
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor called" << std::endl; 
}

void PmergeMe::InsertNums(const std::string &str)
{
	for (int x = 0; x < str.size(); x++)
	{
		if (!std::isdigit(str[x]))
			throw std::invalid_argument("Error");
	}
	int num = std::atoi(str.c_str());
	if (num < 0)
		throw std::invalid_argument("Error"); 
	_vector.push_back(num);
	_list.push_back(num);
}

void PmergeMe::printContainers()
{
	std::cout << "vector: ";
	for (int x = 0; x < _vector.size(); x++)
		std::cout <<  _vector[x] << " ";
	std::cout << std::endl;
	std::cout << "list: ";
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}