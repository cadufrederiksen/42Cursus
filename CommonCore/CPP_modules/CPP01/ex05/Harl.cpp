/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:13:37 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/30 17:02:45 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp" 

Harl::Harl(void)
{
}

Harl::~Harl()
{
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my XXL-double-cheese-triple-picke-special-ketchup burger. I really do!" << std::endl; 
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn`t put enough bacon in my burger! If you did, I wouldn`t be asking for more!"
			  << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I`ve been coming for years whereas you started working here since last mounth"
			  << std::endl; 
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager!" << std::endl;
}

void Harl::complain(std::string level)
{
	ptr_func harl_func[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};  //cria os ponteiro para as funções
	std::string harl_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for(int x = 0; x < 4; x++)
		if(level == harl_level[x])
		{
			(this->*harl_func[x])();//assim se usa a função
			return;
		}
	std::cout << "No such instruction!" << std::endl;
}