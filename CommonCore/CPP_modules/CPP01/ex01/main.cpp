/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:21:13 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 15:01:41 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 4;

	Zombie *zombie = zombieHorde(N, "testingzombies");
	for (int x = 0; x < N; x++)
	{
		zombie[x].announce();
	}
	delete[] zombie;
	return 0;
}