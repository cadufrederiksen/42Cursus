/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:30:21 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/22 20:58:29 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook pb;
	std::string input;

	while (input != "EXIT" && input != "exit")
	{
		std::cout << "Chose one option to interact ADD, SEARCH or EXIT: " << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD" ||input == "add")
			pb.add();
		else if (input == "SEARCH" ||input == "search")
			pb.search();
		else	
			std::cout << "Invalid option" << std::endl;
	}
	return (1);
}