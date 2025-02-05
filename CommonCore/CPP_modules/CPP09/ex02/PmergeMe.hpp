/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:03:37 by carmarqu          #+#    #+#             */
/*   Updated: 2025/02/05 12:18:58 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
	#define PMERGEME_HPP

#include <iostream>

class PmergeMe
{
	public:

	private:
		PmergeMe();
		PmergeMe(const PmergeMe &orig);
		PmergeMe &operator=(const PmergeMe &orig);
		~PmergeMe();
};

#endif