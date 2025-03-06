/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:31:49 by carmarqu          #+#    #+#             */
/*   Updated: 2025/03/06 12:37:53 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span() : _N(0)
{
	std::cout << "Default Span constructor called" << std::endl;
}


Span::Span(unsigned int N) : _N(N)
{
	std::vector<int>_container[N];
	std::cout << "Span constructor called" << std::endl;
}


Span::Span(const Span &orig)
{
	*this = orig;
	std::cout << "Span copy constructor called" << std::endl;
}


Span &Span::operator=(const Span &orig)
{
	if (this != &orig)
	{
		_N = orig._N;
		for (int x = 0; x < orig._N; x++)
			_container[x] = orig._container[x];
	}
	std::cout << "Span copy operator called" << std::endl;
	return (*this);
}

void Span::addNumber(int nbr)
{
	if (_container.size() >= _N)
		throw std::out_of_range("Container is already full");
	else
		_container.push_back(nbr);
}

int	Span::longestSpan() //devolve a maior diferenca entre dois valores
{
	if (_container.size() < 2)
		throw std::out_of_range("Container too small to find a span");
	int max = *std::max_element(_container.begin(), _container.end());//devolve maior e menor int
	int min = *std::min_element(_container.begin(), _container.end());
	return max - min;
}

int Span::shortestSpan()
{
	if (_container.size() < 2)
		throw std::out_of_range("Container too small to find a span");
	std::vector<int> sorted(_container);
	std::sort(sorted.begin(), sorted.end());//ordena del menor a maior
	int diff = sorted[1] - sorted[0];
	for (int i = 1; i < sorted.size() - 1; i++)
	{
		int span = sorted[i + 1] - sorted[i];
		if (diff > span)
			diff = span;
	}
	return diff;
}

void Span::addManyNumbers(unsigned int size)
{
	std::srand(std::time(0));
	for (int x = 0; x < size; x++)
	{
		int random = std::rand() % 10000 + 1;
		_container.push_back(random);
	}
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}