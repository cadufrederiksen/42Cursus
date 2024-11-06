/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:24:35 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/06 16:57:30 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
	#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap{
	 
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		FragTrap &operator=(const FragTrap& copy);
		~FragTrap();
		void highFivedGuys(void);
		
};

#endif