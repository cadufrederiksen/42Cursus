/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:48:24 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/24 13:40:49 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
	#define EASYFIND_HPP

#include <iostream>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &cont, int nbr)
{
	for (typename T::iterator it = cont.begin(); it != cont.end(); it++)
		if (*it == nbr)
			return it;
	throw std::out_of_range ("Number not in the container!");
}

#endif