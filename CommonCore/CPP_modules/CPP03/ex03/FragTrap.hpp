/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:24:35 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/06 17:00:00 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
	#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap{
	 
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		FragTrap &operator=(const FragTrap& copy);
		~FragTrap();
		void highFivedGuys(void);
		
};

#endif