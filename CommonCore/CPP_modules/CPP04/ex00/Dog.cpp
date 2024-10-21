/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:05:04 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/21 20:36:26 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &orig) 
{
	if (this != &orig)
		this->type = orig.type;
	std::cout << "Dog copy operator called" << std::endl;
	return *this;
}

Dog::Dog(const Dog &orig) : Animal(orig)
{
	std::cout << "Dog copy contructor called" << std::endl;
	*this = orig;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Au Au Au!" << std::endl;
}