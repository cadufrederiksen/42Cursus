/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:11:44 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/08 12:38:56 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("name")
{
	this->HitPoints = 100;
	this->AttackDamage = 20;
	this->EnergyPoints = 50;
	std::cout << "ScavTrap default contstructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->AttackDamage = 20;
	this->EnergyPoints = 50;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &orig)
{
	if (this != &orig)//compara os endereços
	{
		this->_name = orig._name;
		this->AttackDamage = orig.AttackDamage;
		this->EnergyPoints = orig.EnergyPoints;
		this->HitPoints = orig.HitPoints;
	}
	std::cout << "ScavTrap copy operator called" << std::endl;
	return *this;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "Scavtrap copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->EnergyPoints == 0)
	{
		std::cout << this->_name << " is out of energy!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->AttackDamage 
				  << " points of damage!" << std::endl;
		this->EnergyPoints -= 1;
	}
}

void ScavTrap::guardGate()
{
	std::cout << this->_name << " is now in Gate keep mode" << std::endl;
}

