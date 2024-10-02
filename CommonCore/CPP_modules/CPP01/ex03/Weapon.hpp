/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:14:21 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 16:00:55 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
	#define WEAPON_HPP

#include <iostream>

class Weapon{

	private:
		std::string type;
	
	public:
		Weapon(std::string type);
		~Weapon();

		const std::string &getType(void);
		void		setType(std::string type);
};

#endif