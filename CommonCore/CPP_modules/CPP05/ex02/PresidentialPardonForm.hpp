/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:32:05 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/06 22:50:15 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
	#define PRESIDENTIALPARDONFORM_HPP
	
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		//PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &orig);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &orig);
		~PresidentialPardonForm();
		
		void execute (Bureaucrat const &executor) const;
};

#endif