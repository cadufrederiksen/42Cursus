/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:21:13 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 14:51:59 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)//array de zombies
{
	Zombie *zombie = new Zombie[N]; //cria o novo array de zombies
	for (int x = 0; x < N; x++)
	{
		zombie[x].set_name(name);
	}
	return zombie;
}