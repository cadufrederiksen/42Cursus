/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:03:34 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/06 17:00:35 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
	#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
	
	private:
		std::string _name;

		
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& orig);
		DiamondTrap& operator=(const DiamondTrap& orig);
		~DiamondTrap();
		
		void attack(const std::string& target);//essa funcao chama a funcao attack de scavtrap
		void whoAmI();
};

#endif