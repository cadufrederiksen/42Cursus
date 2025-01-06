/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:10:18 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/06 17:11:49 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
	#define FORM_HPP
	
#include "Bureaucrat.hpp"	

class Bureaucrat;

class AForm
{
	private:
		const std::string _target;
		bool _signed;
		const int _gradeSign;
		const int _gradeExec;
		AForm();

	public:
		AForm(std::string target, int gradeSign, int gradeExec);
		AForm(const AForm &orig);
		AForm &operator=(const AForm &orig);
		virtual ~AForm();

		void beSigned(const Bureaucrat& obj);
		virtual void	execute(Bureaucrat const &execute) const = 0; //
		// getters
		bool getSigned() const;
		const std::string getTarget() const;
		const int		getGradeExec() const;
		const int		getGradeSign() const;
		
		
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
	
	class FormNotSigned : public std::exception
	{
		public:
			const char *what() const throw() { return "Form is not signed";}
	};
};

#endif