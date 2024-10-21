/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:51:44 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/21 20:36:00 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(std::string name)
{
	type = name;
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal()
{
	type = "Empty";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal&  Animal::operator=(const Animal& orig)
{
	if (this != &orig)
		this->type = orig.type;
	std::cout << "Animal copy operator called" << std::endl;
	return *this;
}

Animal::Animal (const Animal &orig)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = orig;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "Dont know which sound I should do, sorry!" << std::endl;
}