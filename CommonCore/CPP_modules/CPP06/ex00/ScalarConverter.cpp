/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:25:22 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/08 14:59:54 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Scalar converter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &orig)
{
	(void)orig;
	std::cout << "Scalar converter copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &orig)
{
	std::cout << "Scalar converter copy operator called" << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Scalar converter destructor called" << std::endl;
}

void ScalarConverter::converter(std::string *str)
{
	std::cout << str << std::endl;
}