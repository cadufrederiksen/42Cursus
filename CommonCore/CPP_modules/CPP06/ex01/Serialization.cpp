/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:42:11 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/16 13:07:39 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization()
{
	std::cout << "Serialization default constructor called" << std::endl;	
}

Serialization::Serialization(const Serialization &orig)
{
	(void)orig;
	std::cout << "Serialization copy constructor called" << std::endl;	
}

Serialization &Serialization::operator=(const Serialization &orig)
{
	(void)orig;
	std::cout << "Serialization copy operator called" << std::endl;		
	return *this;
}

Serialization::~Serialization()
{
	std::cout << "Serialization destructor called" << std::endl;
}

uintptr_t Serialization::serialize(Data *ptr)
{
	std::cout << "Converting a Data* into a uintptr_t" << std::endl;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serialization::deserialize(uintptr_t raw)
{
	std::cout << "Converting a uintptr_t into a Data *" << std::endl;
	return reinterpret_cast<Data*>(raw);
}