/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:59:40 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/07 16:05:24 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main ()
{
    try 
    {
        Intern randomGuy;
        Bureaucrat bure(10, "Oliver");
        AForm *form = randomGuy.makeForm("robotomy request", "Dom pedro");
        bure.signForm(*form);
        form->execute(bure);
        delete form;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& c)
    {
        std::cerr << c.what() << std::endl;
    }
    
    return 0;
}