/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:38:16 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/04 18:14:37 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int x) : fixedPointValue(x << fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float y) : fixedPointValue(roundf(y * (1 << fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->fixedPointValue) / (1 << fractionalBits);//converte o ponto fixo para
																			// float e divide pelo fator deescala, restaurando o valor original
}

int	  Fixed::toInt(void) const
{
	return this->fixedPointValue >> fractionalBits;
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

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return os;
}