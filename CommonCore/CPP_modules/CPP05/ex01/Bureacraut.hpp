/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureacraut.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:49:13 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/06 17:08:57 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREACRAUT_HPP
	#define BUREACRAUT_HPP

#include <iostream>
#include <exception>
#include <ostream>
#include <string>
#include "Form.hpp"

class Bureacraut
{
	private:
		std::string _name;
		int _grade;
		
	public:
		Bureacraut();
		Bureacraut(int grade, std::string name);
		Bureacraut(const Bureacraut &orig);
		Bureacraut& operator=(const Bureacraut &orig);
		~Bureacraut();
		
		std::string getName() const;
		std::string getGrade() const;
		
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

std::ostream &operator<<(std::ostream &os, const Bureacraut &obj);

#endif