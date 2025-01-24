/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:24:58 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/24 16:09:54 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
	#define SPAN_HPP
	
#include <iostream>
#include <vector>
#include <algorithm>
//#include <stdexcept>


class Span
{
	private:
		std::vector<int> _container;
		unsigned int _N;
	
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &orig);
		Span &operator=(const Span &orig);
		~Span();
	
	void	addNumber(int nbr);
	int		shortestSpan();
	int		longestSpan();
	
};

#endif