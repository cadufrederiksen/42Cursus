/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:01:58 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/15 23:47:08 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main (int argc, char **argv)
{
	FragTrap obj("hola");
	FragTrap outro(obj);
	obj.highFivedGuys();
	outro.highFivedGuys();
}