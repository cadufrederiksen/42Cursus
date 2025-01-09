/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:29:57 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/09 14:03:54 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &orig)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = orig;
}

Intern &Intern::operator=(const Intern &orig)
{
	std::cout << "Intern copy operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern desstructor called" << std::endl;
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	int i = 0;
	while (i < 3 && form != forms[i])
		i++;
	if (i < 3)
		std::cout << "Intern creates " << forms[i] << std::endl;
	AForm *ptr = 0;
	switch (i)
	{
	case 0:
		ptr = new RobotomyRequestForm(target);
		return ptr;
	case 1:
		ptr = new ShrubberyCreationForm(target);
		return ptr;
	case 2:
		ptr = new PresidentialPardonForm(target);
		return ptr;
	default:
		std::cout << "No such form, sorry boss" << std::endl;
		break;
	}
	return NULL;
}