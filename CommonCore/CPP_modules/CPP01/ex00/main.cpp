/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:21:13 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/26 16:22:30 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie zombie("zombie1");
	zombie.announce();
	
	Zombie *zombie2 = newZombie("zombie2");
	zombie2->announce();
	delete zombie2;//chama o destrutor e elimina a memoria
	
	randomChump("zombieStack");
	return 0;
}