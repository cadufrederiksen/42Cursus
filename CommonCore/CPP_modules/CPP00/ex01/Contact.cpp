/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:57:00 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/25 12:43:41 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){
}

Contact::~Contact(void){
}

std::string	Contact::get_fname(void){
	return _fname;
}

std::string	Contact::get_lname(void){
	return _lname;
}

std::string	Contact::get_nickname(void){
	return _nickname;
}

std::string	Contact::get_phone(void){
	return _phone;
}

std::string	Contact::get_secret(void){
	return _secret;
}

void		Contact::set_fname(void){
	std::string input;
	
	while(input.empty() && std::cin.good())
	{
		std::cout << "Please enter your first name: ";
		std::cin >> input;
		if (input.empty())
			std::cout << "First name can't be empty!" << std::endl;
	}
	_fname = input;
}

void		Contact::set_lname(void)
{
	std::string input;
	
	while(input.empty() && std::cin.good())
	{
		std::cout << "Please enter your last name: ";
		std::cin >> input;
		if (input.empty())
			std::cout << "Last name can't be empty!" << std::endl;	
	}
	_lname = input;
}

void		Contact::set_nickname(void)
{
	std::string input;
	
	while(input.empty() && std::cin.good())
	{
		std::cout << "Please enter your nickname: ";
		std::cin >> input;
		if (input.empty())
			std::cout << "Nickname can't be empty" << std::endl;
	}
	_nickname = input;
}

void		Contact::set_phone(void)
{	
	std::string input;
		
	while (input.empty() && std::cin.good())
	{
		std::cout << "Please enter your number: ";
		std::cin >> input;
		if (input.empty())
			std::cout << "Number can't be empty" << std::endl;
		else
		{
			for (int x = 0; x < input.length(); x++)
			{
				if(!std::isdigit(input[x]))
				{
					input.clear();
					std::cout << "Number must be numeric" << std::endl;
					break;
				}
				_phone = input;
			}
		}	
	}
}

void		Contact::set_secret(void)
{
	std::string input;
	
	while(input.empty() && std::cin.good())
	{
		std::cout << "Please enter your darkest secret: ";
		std::cin >> input;
		if (input.empty())
			std::cout << "Your darkest secret can't be empty" << std::endl;
	}
	_secret = input;
}