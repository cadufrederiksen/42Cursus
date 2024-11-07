/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:10:18 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/06 23:40:21 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
	#define FORM_HPP
	
#include "Bureacraut.hpp"	
	
class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeSign;
		const int _gradeExec;

	public:
		Form();
		Form(std::string name, int gradeSign, int gradeExec);
		Form(const Form &orig);
		Form &operator=(const Form &orig);
		~Form();

		void beSigned(const Form &obj);
		
		// getters
		bool getSigned();
		const std::string getName();
		const int		getGradeExec();
		const int		getGradeSign();
		
		
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

#endif