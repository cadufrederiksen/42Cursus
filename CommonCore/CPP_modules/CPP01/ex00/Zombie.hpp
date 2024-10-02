/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:20:12 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/25 16:38:20 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
	#define ZOMBIE_HPP
	
#include <iostream>
	
class Zombie
{
private:
	std::string name;
	
public:
	Zombie(std::string name);
	~Zombie();	
	
	void announce(void);
	
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);


#endif
