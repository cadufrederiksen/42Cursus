/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:19:01 by carmarqu          #+#    #+#             */
/*   Updated: 2025/02/20 13:38:09 by carmarqu         ###   ########.fr       */
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
	std::cout << "Before: ";
	for(int x = 0; x < _vector.size(); x++)
		std::cout << _vector[x] << ' ';
	std::cout << std::endl;

	std::clock_t v_start = std::clock();
	_vector = sortVector(_vector);
	std::clock_t v_end = std::clock();
	
	std::cout << "After: ";
	for(int x = 0; x < _vector.size(); x++)
		std::cout << _vector[x] << ' ';
	std::cout << std::endl;
	
	std::clock_t l_start = std::clock();
	_list = sortList(_list);
	std::clock_t l_end = std::clock();
	
	double vec_time = 1000000.0 * (v_end - v_start) / CLOCKS_PER_SEC;
	double list_time = 1000000.0 * (l_end - l_start) / CLOCKS_PER_SEC;
	std::cout << "Time to process range of " << _vector.size() << " elements with std::vector " << vec_time << " us" << std::endl;
	std::cout << "Time to process range of " << _vector.size() << " elements with std::list " << list_time << " us" << std::endl;
}

//LISTA

std::list<int>	PmergeMe::sortList(std::list<int> &list)
{
	std::list<int> left, right;
	int middle = list.size() / 2;//encontra o meio da lista
	std::list<int>::iterator it = list.begin();
	if (list.size() <= 1)
		return list;
	for (int x = 0; x < middle; x++, it++) //separa a lista em 2, da esquerda e direita
		left.push_back(*it);
	for (; it != list.end(); it++)
		right.push_back(*it);
	left = sortList(left);//divide recursivamente ate sobrar apenas 2
	right = sortList(right);
	return (mergeList(left, right));//ordena a lista 
}

std::list<int> PmergeMe::mergeList(std::list<int> &left, std::list<int> &right)
{
	std::list<int> result;
	std::list<int>::iterator it_r = right.begin(), it_l = left.begin();
	
	while(it_r != right.end() && it_l != left.end())//itera as listas ao mesmo tempo
	{
		if(*it_l < *it_r)//se o da direita for maior, push para lista da esquerda
		{
			result.push_back(*it_l);
			it_l++;
		}
		else //se o da esquerda for maior, push para direita (ordena deixando o menor a esquerda)
		{
			result.push_back(*it_r);
			it_r++;
		}
	}
	result.insert(result.end(), it_l, left.end());//coloca a lista da esquerda em result
	result.insert(result.end(), it_r, right.end());//coloca a lista da direita em result
	return result;
}

//VECTOR

std::vector<int>	PmergeMe::sortVector(std::vector<int> &vec)
{
	std::vector<int> left, right;
	int middle = vec.size() / 2;
	std::vector<int>::iterator it = vec.begin();
	if (vec.size() <= 1)
		return vec;
	for (int x = 0; x < middle; x++, it++)
		left.push_back(*it);
	for (; it != vec.end(); it++)
		right.push_back(*it);
	left = sortVector(left);
	right = sortVector(right);
	return (mergeVector(left, right));
}

std::vector<int> PmergeMe::mergeVector(std::vector<int> &left, std::vector<int> &right)
{
	std::vector<int> result;
	std::vector<int>::iterator it_r = right.begin(), it_l = left.begin();
	
	while(it_r != right.end() && it_l != left.end())
	{
		if(*it_l < *it_r)
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
	result.insert(result.end(), it_l, left.end());
	result.insert(result.end(), it_r, right.end());
	return result;
}

