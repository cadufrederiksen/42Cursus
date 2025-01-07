/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:04:58 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/07 14:17:01 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
	std::cout << "Shrubbery Creation Form constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &orig) : AForm(orig)
{
	std::cout << "Shrubbery Creation Form copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &orig)
{
	if (this != &orig)
		AForm::operator=(orig);
	std::cout << "Shrubbery Creation Form copy operator called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (!getSigned())
			throw AForm::FormNotSigned();
		if (executor.getGrade() > this->getGradeExec())
			throw AForm::GradeTooLowException();
		std::ofstream newfile (getTarget() + "_shrubbery");
		if (newfile.is_open())
		{
			newfile << "       _-_\n";
      		newfile << "    /~~   ~~\\\n";
        	newfile << " /~~         ~~\\\n";
        	newfile << "{               }\n";
        	newfile << " \\  _-     -_  /\n";
        	newfile << "   ~  \\ //  ~\n";
        	newfile << "_- -   | | _- _\n";
        	newfile << "  _ -  | |   -_\n";
        	newfile << "      // \\\n";
			newfile.close();
		}
		else
			std::cout << "Failure while opening file " << getTarget() << "_shrubbery" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << executor.getName() << " couldn't execute the form because " << e.what() << '\n';	
	}
	
}