/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:29:29 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 17:10:53 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
	#define HUMANA_HPP
	
#include "Weapon.hpp"	

class HumanA{
	
	private:
		std::string name;
		Weapon &_weapon; //cria uma referencia	
	
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		
	void attack(void);
};

#endif