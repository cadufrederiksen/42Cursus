/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:10:47 by carmarqu          #+#    #+#             */
/*   Updated: 2024/12/03 16:49:21 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("name"), _signed(false), _gradeSign(150), _gradeExec(0)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
    std::cout << "Form constructor called" << std::endl;
    if (_gradeSign < 1 || _gradeExec < 1)
        throw Form::GradeTooHighException();
    else if (_gradeSign > 150 || _gradeExec > 150)
        throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form &orig)
{
    if (this != &orig)
        this->_signed = orig._signed;
    std::cout << "Form copy operator called" << std::endl;
    return *this;
}

Form::Form(const Form &orig) : _name(orig._name), _gradeExec(orig._gradeExec), _gradeSign(_gradeSign)
{
    *this = orig;
    std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

bool Form::getSigned() const
{
    return _signed;
}

const std::string Form::getName() const
{
    return _name;
}

const int Form::getGradeExec() const
{
    return _gradeExec;
}

const int Form::getGradeSign() const
{
    return _gradeSign;
}

void Form::beSigned(const Bureaucrat &obj)
{
    if (obj.getGrade() > this->_gradeSign)
        throw Form::GradeTooLowException();
    else
    {
        _signed = true;
        std::cout << obj.getName() << " signed " << this->_name << std::endl;
    }
}