/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:10:18 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/05 15:38:46 by carmarqu         ###   ########.fr       */
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
		Form(std::string name, int _gradeSign, int _gradeExec);
		Form(const Form &orig);
		Form &operator=(const Form &orig);
		~Form();

		void beSigned(const Form &obj);
		bool getSigned();
		std::string getName();
		int 		getGradeExec();
		int 		getGradeSign();
		
		
	class ClassTooLowException : public std::exception
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