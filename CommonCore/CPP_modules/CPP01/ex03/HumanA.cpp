/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:53:41 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 17:16:00 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), _weapon(weapon) {}// lista de inicialização

HumanA::~HumanA()
{}

void	HumanA::attack()
{
	if (_weapon.getType().empty())
		std::cout << name << "has no weapon" << std::endl;
	else
		std::cout << name << " attacks with their " << _weapon.getType() << std::endl;
}