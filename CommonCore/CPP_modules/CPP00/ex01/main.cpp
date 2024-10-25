/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:30:21 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/25 12:36:11 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook pb;
	std::string input;

	std::cout << "Chose one option to interact ADD, SEARCH or EXIT: " << std::endl;
	while (input != "EXIT" && input != "exit" && (std::cin >> input))
	{
		//std::getline(std::cin, input);
		if (input == "ADD" ||input == "add")
			pb.add();
		else if (input == "SEARCH" ||input == "search")
			pb.search();
		else	
			std::cout << "Invalid option" << std::endl;
		std::cout << "Chose one option to interact ADD, SEARCH or EXIT: " << std::endl;
	}
	return (1);
}