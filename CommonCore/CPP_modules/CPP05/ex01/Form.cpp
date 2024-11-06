/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:10:47 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/06 17:42:15 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("name"), _signed(false), _gradeSign(150), _gradeExec(150);
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
    return 0;
}

Form &Form::operator=(const Form &orig)
{
    if (this != &orig)
    {
        this->_name = Form._name;
        this->_signed = Form._signed
        this->_gradeSign = Form._gradeSign;
        this->_gradeExec = Form._gradeExec;
    }
    std::cout << "Form copy operator called" << std::endl;
    return *this;
}

Form::Form(Const Form &orig)
{
    *this = orig;
    std::cout << "Form copy constructor called" << std::endl;
}


