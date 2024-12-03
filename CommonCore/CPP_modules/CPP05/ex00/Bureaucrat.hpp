/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:49:13 by carmarqu          #+#    #+#             */
/*   Updated: 2024/12/03 16:54:30 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
	#define Bureaucrat_HPP

#include <iostream>
#include <exception>
#include <ostream>
#include <string>


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
		std::string getGrade() const;
		
		void IncrementGrade(int value);
		void DecrementGrade(int value);
		
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