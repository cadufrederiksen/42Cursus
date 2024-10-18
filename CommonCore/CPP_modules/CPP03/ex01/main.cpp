/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:01:58 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/15 19:07:08 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main (int argc, char **argv)
{
	ScavTrap obj("obj") ;
	obj.attack("hola");
	obj.takeDamage(20);
	obj.attack("hola");
	obj.takeDamage(100);
	obj.attack("hola");
	obj.attack("hola");
	obj.attack("hola");
	obj.attack("hola");
	obj.attack("hola");
	obj.attack("hola");
	obj.attack("hola");
	obj.attack("hola");
	obj.attack("hola");
	obj.beRepaired(7);
}