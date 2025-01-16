/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:29:04 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/16 14:16:46 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

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

void Base::identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type: C" << std::endl;
	else 
		std::cout << "Type: Unknown" << std::endl;
}
void Base::identify (Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type: A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type: B" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type: C" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	
	std::cout << "Type: Unknown" << std::endl;
	
}