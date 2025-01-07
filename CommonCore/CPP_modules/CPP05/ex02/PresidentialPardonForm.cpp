/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:41:35 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/07 14:18:28 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target , 25, 5)
{
	std::cout << "Presidential Pardon Form constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form destructor called" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &orig)
{
	if (this != &orig)
		AForm::operator=(orig);
	std::cout << "Presidential Pardon Form operator called" << std::endl;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &orig) : AForm(orig)
{
	std::cout << "Presidential Pardon Form copy constructor called" << std::endl;
}

void	PresidentialPardonForm::execute (Bureaucrat const &executor) const
{	
	try
	{
		if (!getSigned())
			throw AForm::FormNotSigned();
		if (executor.getGrade() > this->getGradeExec())
			throw AForm::GradeTooLowException();
		std::cout << executor.getName() << " has been perdoned by Zaphod Beeblebrox" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << executor.getName() << " couldn't execute the form because " << e.what() << '\n';	
	}
	
}