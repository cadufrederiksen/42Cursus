/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureacrautBureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:45:38 by carmarqu          #+#    #+#             */
/*   Updated: 2024/12/03 16:48:12 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(150), _name("name")
{
	std::cout << "Bureaucrat default contructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade, const std::string name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}  
	else
	{
		_grade = grade;
		_name = name;
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &orig)
{
	if (this != &orig)
	{
		this->_grade = orig._grade;
		this->_name = orig._name;
	}
	std::cout << "Bureaucrat copy operator called" << std::endl;
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &orig)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = orig;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::IncrementGrade(int value)
{
	if (_grade - value < 1)
		throw Bureaucrat::GradeTooHighException();
	else 
		_grade -= value;
}

void Bureaucrat::DecrementGrade(int value)
{
	if (_grade + value > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade += value;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getGrade() << ", Bureaucrat grade " << obj.getGrade();
	return (os);
}

void Bureaucrat::signForm(Form& form)
{ 
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
	}
}