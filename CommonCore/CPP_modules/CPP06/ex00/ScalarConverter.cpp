/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:25:22 by carmarqu          #+#    #+#             */
/*   Updated: 2025/02/26 13:33:53 by carmarqu         ###   ########.fr       */
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
	(void)orig;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Scalar converter destructor called" << std::endl;
}

void ScalarConverter::converter(const std::string &str)
{
	std::string types[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	int i = 0;
	char c = 0;
	double d = 0;
	float f = 0;
	int x = 0;
	
	while (x < 6 && str != types[x])
		x++;
	if (x == 6 && !std::isdigit(str[0]) && !std::isdigit(str[1]) && str.length() > 1)
	{
		std::cerr << "Error: Invalid input" << std::endl;
		return ;
	} 
	if (str.length() == 1 && !std::isdigit(str[0]))//is a char
	{
		c = str[0];
		i = static_cast<int>(c);
	}
 	else
	{
		if (str.find('.') != std::string::npos)//have a dot
		{
			if (str[str.length() - 1] == 'f')//is a float
			{
				f = std::stof(str);
				i = static_cast<int>(f);
			}
			else
			{
				d = std::stod(str);
				i = static_cast<int>(d);
			}
		}
		else
			i = std::stoi(str);
	}
	if (x > 5)
	{	
		if (i < 126 && i > 31)
			std::cout << "char: " << static_cast<char>(i) << std::endl;
		else
			std::cout << "char: non printable" << std::endl;
		std::cout << "int: " << i << std::endl;
		if (!f && !d)
		{
			std::cout << "float: " << static_cast<float>(i) << ".0f"<< std::endl;
			std::cout << "double: " << static_cast<double>(i) << ".0"<< std::endl;
		}
		else if (!f)
		{
			std::cout << "float: " << static_cast<float>(d) << "f"<< std::endl;
			std::cout << "double: " << d << std::endl;
		}
		else
		{
			std::cout << "float: " << f << "f" <<std::endl;
			std::cout << "double: " << static_cast<double>(f) << std::endl;
		}
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (x < 3)
		{
			std::cout << "float: " << types[x] << std::endl;
			std::cout << "double: " << types[x].erase(str.length() - 1) << std::endl;
		}
		else
		{	
			std::cout << "float: " << types[x] + 'f' << std::endl;
			std::cout << "double: " << types[x] << std::endl;
		}
	}
}