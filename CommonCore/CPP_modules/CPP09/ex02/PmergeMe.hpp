/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:03:37 by carmarqu          #+#    #+#             */
/*   Updated: 2025/02/20 13:26:04 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
	#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <ctime>

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
		
		void				Pmerge();
		void				InsertNums(const std::string &str);
		std::list<int>		sortList(std::list<int> &vec);
		std::list<int>		mergeList(std::list<int> &left, std::list<int> &right);
		std::vector<int>	sortVector(std::vector<int> &vec);
		std::vector<int>	mergeVector(std::vector<int> &left, std::vector<int> &right);

};

#endif