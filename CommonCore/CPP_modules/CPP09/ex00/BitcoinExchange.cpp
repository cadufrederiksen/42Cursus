/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:06:54 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/30 17:05:35 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &orig)
{
	*this = orig;
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &orig)
{
	if (this != &orig)
		_exchangeData = orig._exchangeData;
	std::cout << "BitcoinExchange copy operator called" << std::endl;
	return *this;
};

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
};

bool BitcoinExchange::getExchangeData(const std::string &file)
{
	std::ifstream infile(file);
	std::string date, value, line;
	if (!infile.is_open())
		return false;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		if (line == "date,exchange_rate")
			continue ; //pula uma linha do bucle
		else if (std::getline(iss, date, ',') && std::getline(iss, value))
			this->_exchangeData[date] = std::stod(value.c_str());
		else
			std::cerr << "Error parsing the line" << line << std::endl;
	}
	return true;
}

void BitcoinExchange::returnValue(std::string date, double value)
{
	std::map<std::string, double>::iterator it = _exchangeData.find(date);
	double price;
	
	if (it != _exchangeData.end())
		price = it->second;
	else //find() devuelve end() si no encontra o valor 
	{
		it = _exchangeData.upper_bound(date);
		if (it != _exchangeData.begin())
			it--;
		price = it->second;
	}
	std::cout << date << " => " << value << " => " << price * value << std::endl;
}
