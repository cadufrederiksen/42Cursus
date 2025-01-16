/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:36:13 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/16 14:57:52 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
	#define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap(T &a, T&b)
{
	T temp = b;
	b = a;
	a = temp;
};

template <typename T>
T min(T&a, T&b)
{
	if (a < b)
		return a;
	else 
		return b;
};

template <typename T>
T max(T&a, T&b)
{
	if (a > b)
		return a;
	else 
		return b;
};

#endif