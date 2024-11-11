/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:01:58 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/08 12:41:59 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main (int argc, char **argv)
{
	ScavTrap obj("obj") ;
	ClapTrap obj2("prueba");
	obj2.attack("test");
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
	obj.guardGate();
}