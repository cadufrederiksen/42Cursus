/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:37:08 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/08 12:42:10 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("name")
{
	this->HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	ClapTrap::AttackDamage = 20;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &orig)
{
	if (this != &orig)//compara os endereços
	{
		this->_name = orig._name;
		this->AttackDamage = orig.AttackDamage;
		this->EnergyPoints = orig.EnergyPoints;
		this->HitPoints = orig.HitPoints;
	}
	std::cout << "FragTrap copy operator called" << std::endl;
	return *this;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap (copy)
{
	std::cout << "FragTrap copy constructo called" << std::endl;
	*this = copy;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivedGuys(void)
{
	std::cout << this->_name << " is requesting a high five!" << std::endl;
}