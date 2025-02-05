/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:03:37 by carmarqu          #+#    #+#             */
/*   Updated: 2025/02/05 14:44:22 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
	#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <sstream>

class PmergeMe
{
	private:
		std::list<int> _list;
		std::vector<int> _vector;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &orig);
		PmergeMe &operator=(const PmergeMe &orig);
		~PmergeMe();
		
		void	InsertNums(const std::string &str);
		void	sortVector();

};

#endif