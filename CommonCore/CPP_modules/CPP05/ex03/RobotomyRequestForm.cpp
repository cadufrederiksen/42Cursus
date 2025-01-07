/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:14:20 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/07 14:16:35 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm (target, 72, 45)
{
	std::cout << "Robotomy Request Form constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &orig)
{
	if (this != &orig)
		AForm::operator=(orig);
	std::cout << "Robotomy Request Form operator called" << std::endl;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &orig) : AForm(orig)
{
	std::cout << "Robotomy Request Form copy constructor called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (!getSigned())
			throw AForm::FormNotSigned();
		if (executor.getGrade() > this->getGradeExec())
			throw AForm::GradeTooLowException();
		std::srand(std::time(0));//inicia a semente do gerador
		int random_num = std::rand();
		std::cout << "Making drilling noise ZzzZZzzzZZZ..." << std::endl;
		if (random_num % 2 == 0)
			std::cout << executor.getName() << " has been robotomized successfully" << std::endl;
		else
			std::cout << executor.getName() << " has failed while robototomized" << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << executor.getName() << " couldn't execute the form because " << e.what() << '\n';	
	}
	
}