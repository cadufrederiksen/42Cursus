/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:39:12 by carmarqu          #+#    #+#             */
/*   Updated: 2025/02/04 15:39:01 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool CheckInput(std::string input)
{
	unsigned int nbrs = 0, signals = 0;
	
	if (input.empty())
		return false;
	for (int x = 0; x < input.size(); x++)
	{
		if (!std::isdigit(input[x]) && input[x] != '*' && input[x] != '+' 
			&& input[x] != '-' && input[x] != '/' && input[x] != ' ')
				return false;
		if (std::isdigit(input[x]))
		{
			if (std::isdigit(input[x + 1]))
				return false;
			nbrs++;
		}
		else if (input[x] != ' ')
			signals++;
	}
	if (nbrs != signals + 1)
		return false;
	return true;
	
}

int main(int argc, char **argv)
{
	RPN obj;
	
	if (argc != 2)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return 1;
	}
	std::string input = argv[1];
	if (CheckInput(argv[1]))
		obj.addDeque(argv[1]);
	else
		std::cerr << "Error" << std::endl;
}