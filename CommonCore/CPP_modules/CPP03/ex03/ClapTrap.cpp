/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:28:15 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/15 18:30:51 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), HitPoints(10), EnergyPoints(10), AttackDamage (0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;// usa o operador de cópia, então copia todos os atributos
}

ClapTrap& ClapTrap::operator=(const ClapTrap &orig)
{
	if (this != &orig)//compara os endereços
	{
		this->_name = orig._name;
		this->AttackDamage = orig.AttackDamage;
		this->EnergyPoints = orig.EnergyPoints;
		this->HitPoints = orig.HitPoints;
	}
	std::cout << "Copy operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor Called" << std::endl;
}

void ClapTrap::attack (const std::string& target)
{
	if (this->EnergyPoints == 0)
	{
		std::cout << this->_name << " is out of energy!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->AttackDamage 
				  << " points of damage!" << std::endl;
		this->EnergyPoints -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints <= amount)
	{
		std::cout << this->_name << " is dead" << std::endl;
		this->HitPoints = 0;
	}
	else
	{
		std::cout << this->_name << " has taken " << amount << " hit points" << std::endl;
		this->HitPoints -= amount;
	}
}

void ClapTrap::beRepaired (unsigned int amount)
{
	if (this->EnergyPoints == 0)
	{
		std::cout << this->_name << " is out of energy!" << std::endl;
	}
	else
	{
		std::cout << this->_name << " has realed " << amount << " hit points!" << std::endl;
		this->HitPoints += amount;
		this->EnergyPoints -= 1;
	}
}