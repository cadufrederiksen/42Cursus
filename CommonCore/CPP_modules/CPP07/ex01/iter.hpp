/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:02:27 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/16 15:08:56 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
	#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *array, int len, void (*func)(T&))
{
	for (int i = 0; i < len; i++)
		func(array[i]);
};
template <typename T>
void	print_iter(T &t)
{
	std::cout << t << std::endl;
}

#endif