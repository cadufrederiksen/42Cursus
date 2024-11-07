/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:03:28 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/07 12:27:04 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("name_clap_name"), FragTrap("name"), ScavTrap("name")
{
	this->_name = "name";
	HitPoints = FragTrap::HitPoints;
	EnergyPoints = ScavTrap::EnergyPoints;
	AttackDamage = FragTrap::AttackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	//ClapTrap::_name = name + "_clap_name";
	HitPoints = FragTrap::HitPoints;
	EnergyPoints = ScavTrap::EnergyPoints;
	AttackDamage = FragTrap::AttackDamage;
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& orig) : ClapTrap(orig), FragTrap(orig),  ScavTrap(orig)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = orig;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& orig)
{
	if (this != &orig)
	{
		this->_name = orig._name;
		this->HitPoints = orig.HitPoints;
		this->AttackDamage = orig.AttackDamage;
		this->EnergyPoints = orig.EnergyPoints;
	}
	std::cout << "DiamondTrap copy operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}