/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:11:40 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/21 21:56:33 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &orig)
{
	if (this != &orig)
		this->type = orig.type;
	std::cout << "Cat copy operator called" << std::endl;
	return *this;
}

Cat::Cat(const Cat &orig) : Animal(orig)
{
	std::cout << "Cat copy contructor called" << std::endl;
	*this = orig;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miau Miau Miau!" << std::endl;
}
