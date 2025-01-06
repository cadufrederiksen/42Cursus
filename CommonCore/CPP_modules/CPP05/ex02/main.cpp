/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:59:40 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/03 15:46:32 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main ()
{
    try 
    {
        Bureaucrat b(120, "John");
        Form a("form", 150, 150);
        std::cout << b << std::endl;
        b.DecrementGrade(11);
        std::cout << b << std::endl;
        b.IncrementGrade(12);
        b.signForm(a);
        std::cout << b << std::endl;
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