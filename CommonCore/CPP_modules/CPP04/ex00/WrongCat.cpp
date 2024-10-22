/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.Cat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:56:26 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/21 21:56:27 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &orig)
{
	if (this != &orig)
		this->type = orig.type;
	std::cout << "WrongCat copy operator called" << std::endl;
	return *this;
}

WrongCat::WrongCat(const WrongCat &orig) : WrongAnimal(orig)
{
	std::cout << "WrongCat copy contructor called" << std::endl;
	*this = orig;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Auuuuuuuuuuuu!" << std::endl;
}
