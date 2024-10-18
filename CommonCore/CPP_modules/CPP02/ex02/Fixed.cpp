/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:38:16 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/05 22:40:54 by carmarqu         ###   ########.fr       */
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
	return static_cast<float>(this->fixedPointValue) / (1 << fractionalBits);//converte o ponto fixo para float e divide pelo fator deescala, restaurando o valor original
}

int	  Fixed::toInt(void) const
{
	return this->fixedPointValue >> fractionalBits;
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

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)//objeto atual é diferente da cópia do endereço de copy
		this->fixedPointValue = copy.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)//direciona o objeto para o fluxo de saida
{
	os << obj.toFloat();
	return os;
}

//operadores de comparação

bool Fixed::operator<(const Fixed &fxd) const
{
	return this->fixedPointValue < fxd.fixedPointValue;
}

bool Fixed::operator>(const Fixed &fxd) const
{
	return this->fixedPointValue > fxd.fixedPointValue;//pode ser a função gerRawBits
}

bool Fixed::operator<=(const Fixed &fxd) const
{
	return this->fixedPointValue <= fxd.fixedPointValue;
}

bool Fixed::operator>=(const Fixed &fxd) const
{
	return this->fixedPointValue >= fxd.fixedPointValue;
}

bool Fixed::operator==(const Fixed &fxd) const
{
	return this->fixedPointValue == fxd.fixedPointValue;
}

bool Fixed::operator!=(const Fixed &fxd) const
{
	return this->fixedPointValue != fxd.fixedPointValue;
}

//operadores aritméticos

Fixed Fixed::operator+(const Fixed &fxd) const
{
	return this->toFloat() + fxd.toFloat();
}

Fixed Fixed::operator-(const Fixed &fxd) const
{
	return this->toFloat() - fxd.toFloat();
}

Fixed Fixed::operator/(const Fixed &fxd) const
{
	if (fxd.toFloat() == 0)
		return 0;
	else
		return this->toFloat() / fxd.toFloat();
}

Fixed Fixed::operator*(const Fixed &fxd) const
{
	return this->toFloat() * fxd.toFloat();
}

//operadores de incrementar/decrementar

Fixed &Fixed::operator++(void)
{
	++this->fixedPointValue;
	return *this;
}

Fixed &Fixed::operator--(void)
{
	--this->fixedPointValue;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this; //cópia do objeto atual
	++this->fixedPointValue; //incrementa o valor do objeto atual
	return tmp; //devolve a cópia feita antes (objeto "antigo")
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this; //cópia do objeto atual
	--this->fixedPointValue; //incrementa o valor do objeto atual
	return tmp; //devolve a cópia feita antes (objeto "antigo")
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.fixedPointValue < b.fixedPointValue)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.fixedPointValue < b.fixedPointValue)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.fixedPointValue > b.fixedPointValue)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.fixedPointValue > b.fixedPointValue)
		return a;
	return b;
}