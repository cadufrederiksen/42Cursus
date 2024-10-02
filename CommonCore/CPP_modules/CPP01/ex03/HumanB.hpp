/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:40:27 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 16:43:08 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
	#define HUMANB_HPP
	
#include "Weapon.hpp"
	
class HumanB{

	private:
		std::string name;
		Weapon *_weapon;//cria um ponteiro

	public:
		HumanB(std::string name);
		~HumanB();
		
		void setWeapon(Weapon &weapon);
		void attack(void);
};

#endif