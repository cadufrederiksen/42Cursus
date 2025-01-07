/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:10:47 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/07 14:16:00 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _target("name"), _signed(false), _gradeSign(150), _gradeExec(0)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _target(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
    std::cout << "AForm constructor called" << std::endl;
    if (_gradeSign < 1 || _gradeExec < 1)
        throw AForm::GradeTooHighException();
    else if (_gradeSign > 150 || _gradeExec > 150)
        throw AForm::GradeTooLowException();
}

AForm &AForm::operator=(const AForm &orig)
{
    if (this != &orig)
        this->_signed = orig._signed;
    std::cout << "AForm copy operator called" << std::endl;
    return *this;
}

AForm::AForm(const AForm &orig) : _target(orig._target), _gradeExec(orig._gradeExec), _gradeSign(_gradeSign)
{
    *this = orig;
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

bool AForm::getSigned() const
{
    return _signed;
}

const std::string AForm::getTarget() const
{
    return _target;
}

const int AForm::getGradeExec() const
{
    return _gradeExec;
}

const int AForm::getGradeSign() const
{
    return _gradeSign;
}

void AForm::beSigned(const Bureaucrat &obj)
{
    if (obj.getGrade() > this->_gradeSign)
        throw AForm::GradeTooLowException();
    else
    {
        _signed = true;
        std::cout << obj.getName() << " signed the form" << std::endl;
    }
}