/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:29:04 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/10 15:42:36 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << "Base destructor called" << std::endl;
}

Base* Base::generate()
{
	std::srand(std::time(0));
	
	int random = std::rand() % 3 + 1;
	
	switch (random)
	{
		case 1:
			return new A();
		case 2:
			return new B();
		case 3:
			return new C();
		default:
			return nullptr;
	}
}
