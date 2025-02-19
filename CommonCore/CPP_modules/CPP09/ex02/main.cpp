/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:46:29 by carmarqu          #+#    #+#             */
/*   Updated: 2025/02/11 11:53:30 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe obj;
	
	try
	{
		for (int x = 1; x < argc; x++)
			obj.InsertNums(argv[x]);
		obj.printContainers();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}