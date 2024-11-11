/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureacraut.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:45:38 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/08 15:49:27 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureacraut.hpp"

Bureacraut::Bureacraut() : _grade(150), _name("name")
{
	std::cout << "Bureacraut default contructor called" << std::endl;
}

Bureacraut::Bureacraut(int grade, const std::string name)
{
	std::cout << "Bureacraut constructor called" << std::endl;
	if (grade < 1)
		throw Bureacraut::GradeTooHighException();
	else if (grade > 150)
	{
		throw Bureacraut::GradeTooLowException();
	}  
	else
	{
		_grade = grade;
		_name = name;
	}
}

Bureacraut& Bureacraut::operator=(const Bureacraut &orig)
{
	if (this != &orig)
	{
		this->_grade = orig._grade;
		this->_name = orig._name;
	}
	std::cout << "Bureacraut copy operator called" << std::endl;
	return *this;
}

Bureacraut::Bureacraut(const Bureacraut &orig)
{
	std::cout << "Bureacraut copy constructor called" << std::endl;
	*this = orig;
}

Bureacraut::~Bureacraut()
{
	std::cout << "Bureacraut destructor called" << std::endl;
}

std::string Bureacraut::getName() const
{
	return _name;
}

int Bureacraut::getGrade() const
{
	return _grade;
}

void Bureacraut::IncrementGrade(int value)
{
	if (_grade - value < 1)
		throw Bureacraut::GradeTooHighException();
	else 
		_grade -= value;
}

void Bureacraut::DecrementGrade(int value)
{
	if (_grade + value > 150)
		throw Bureacraut::GradeTooLowException();
	else
		_grade += value;
}

std::ostream &operator<<(std::ostream &os, const Bureacraut &obj)
{
	os << obj.getGrade() << ", bureacraut grade " << obj.getGrade();
	return (os);
}

void Bureacraut::signForm(Form& form)
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