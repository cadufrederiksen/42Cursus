/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:04:13 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/25 12:44:13 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	std::cout << "Welcome to your new Phonebook!" << std::endl;//colocar comando ADD, SEARCH e EXIT
	index = 0;	
	nr_contact = 0;
}

PhoneBook::~PhoneBook(void){
	std::cout << "Closing your Phonebook!" << std::endl;
}

void	PhoneBook::add(void){
	
	if (index == 8)
		index = 0;
	if (nr_contact > 7)
	{
		std::cout << "Deleting information about " << _contact[index].get_fname() << std::endl;
		nr_contact = 8;
	}
	_contact[index].set_fname();
	_contact[index].set_lname();
	_contact[index].set_nickname();
	_contact[index].set_phone();
	_contact[index].set_secret();
	index++;
	nr_contact++;
}

std::string 	PhoneBook::check_str(std::string str)
{
	int size = str.length();
	
	if (size > 9)
	{
		std::string new_str = str.substr(0, 9);
		new_str.insert(9, ".");
		return (new_str);
	}
	return(str);
}

void	PhoneBook::search(void)
{
	if (nr_contact == 0)
	{
		std::cout << "No contacts in the Phonebook!" << std::endl;
		return;
	}
	int x = 0;
	
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	while(x < nr_contact)
	{
		std::cout << std::setw(10) << x << "|";
		std::cout << std::setw(10) << PhoneBook::check_str(_contact[x].get_fname()) << "|";
		std::cout << std::setw(10) << PhoneBook::check_str(_contact[x].get_lname()) << "|";
		std::cout << std::setw(10) << PhoneBook::check_str(_contact[x].get_nickname()) << "|" << std::endl;
		x++;
	}
	std::string input;
	std::cout << "Select a index: ";
	std::cin >> input;
	if ((input[0] && (input[0] >= '0' && input[0] <= '7')) && input.length() == 1)
	{
		int idx = input[0] - '0';
		if (idx < nr_contact)
		{
			std::cout << "First name: " << _contact[idx].get_fname() << std::endl;
			std::cout << "Last name: " << _contact[idx].get_lname() << std::endl;
			std::cout << "Nickname: " << _contact[idx].get_nickname() << std::endl;
			std::cout << "Phone: " << _contact[idx].get_phone() << std::endl;
			std::cout << "Darkest Secret: " << _contact[idx].get_secret() << std::endl;
		}
		else
			std::cout << "No contact with this index!" << std::endl;
	}
	else
		std::cout << "Invalid Index!" << std::endl;
	
}
