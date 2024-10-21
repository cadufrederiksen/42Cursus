/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:56:12 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/21 21:56:53 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string name)
{
	type = name;
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal()
{
	type = "Empty";
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal&  WrongAnimal::operator=(const WrongAnimal& orig)
{
	if (this != &orig)
		this->type = orig.type;
	std::cout << "WrongAnimal copy operator called" << std::endl;
	return *this;
}

WrongAnimal::WrongAnimal (const WrongAnimal &orig)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = orig;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Dont know which sound I should do, sorry!" << std::endl;
}