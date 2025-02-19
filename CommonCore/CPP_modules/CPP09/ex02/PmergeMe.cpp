/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:19:01 by carmarqu          #+#    #+#             */
/*   Updated: 2025/02/11 16:05:54 by carmarqu         ###   ########.fr       */
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

std::list<int>	PmergeMe::sortList(std::list<int> &vec)
{
	std::list<int> left, right;
	int middle = vec.size() / 2;
	std::list<int>::iterator it = vec.begin();
	if (vec.size() <= 1)
		return vec;
		
	for (int x = 0; x < middle; x++, it++) //separa a lista em 2, da esquerda e direita
		left.push_back(*it);
	for (; it != vec.end(); it++)
		right.push_back(*it);
	left = sortList(left);
	right = sortList(right);
	return (mergeList(left, right));
}

std::list<int> PmergeMe::mergeList(std::list<int> &left, std::list<int> &right)
{
	std::list<int> result;
	std::list<int>::iterator it_r = right.begin(), it_l = left.begin();
	
	while(it_r != right.end() && it_l != left.end())
	{
		if(*it_l < *it_r)//adiciona o menor número em result
		{
			result.push_back(*it_l);
			it_l++;
		}
		else
		{
			result.push_back(*it_r);
			it_r++;
		}
	}
	std::cout << "left ";
	printList(left);
	result.insert(result.end(), it_l, left.end());
	std::cout << "right ";
	printList(right);
	result.insert(result.end(), it_r, right.end());
	return result;
}

void PmergeMe::InsertNums(const std::string &str)
{
	for (int x = 0; x < str.size(); x++)
	{
		if(!std::isdigit(str[x]))
			throw std::invalid_argument("Error");
	}
	int num = std::atoi(str.c_str());
	if (num < 0)
		throw std::invalid_argument("Error"); 
	_vector.push_back(num);
	_list.push_back(num);
}

void	PmergeMe::Pmerge()
{
	_list = sortList(_list);
	printList(_list);
}

void PmergeMe::printList(const std::list<int> &lst) const
{
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}