/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:26:59 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/25 17:18:24 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name)//stack
{
	Zombie zombie(name);
	zombie.announce();
}

//Objetos criados no stack sao alocados e liberados automaticamente