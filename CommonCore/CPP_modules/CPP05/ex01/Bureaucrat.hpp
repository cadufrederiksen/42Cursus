/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:49:13 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/03 15:41:33 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
	#define Bureaucrat_HPP

#include <iostream>
#include <exception>
#include <ostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string _name;
		int _grade;
		
	public:
		Bureaucrat();
		Bureaucrat(int grade, std::string name);
		Bureaucrat(const Bureaucrat &orig);
		Bureaucrat& operator=(const Bureaucrat &orig);
		~Bureaucrat();
		
		std::string getName() const;
		int			getGrade() const;
		
		void IncrementGrade(int value);
		void DecrementGrade(int value);
		
		void signForm(Form &form);
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw() { return "Grade is lower than the range"; };
		};

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw() { return "Grade is higher than the range";}
		};

		
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif