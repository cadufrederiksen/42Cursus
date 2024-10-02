/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:20:12 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 14:51:32 by carmarqu         ###   ########.fr       */
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
	Zombie();
	~Zombie();	
	
	void announce(void);
	void set_name(std::string name);
	
};

Zombie *zombieHorde(int N, std::string name);

#endif
