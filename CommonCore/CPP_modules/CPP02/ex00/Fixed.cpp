/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:30:36 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/04 16:35:36 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(copy.getRawBits());//copia o valor interno do de um objeto fixed para outro, garantindo o mesmo estados nos dois objetos
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)//objeto atual é diferente da cópia do endereço de copy
		this->fixedPointValue = copy.getRawBits();
	return *this;
}

void Fixed::setRawBits (int const raw)
{
	this->fixedPointValue = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getrawBits member function called" << std::endl;
	return this->fixedPointValue;
}