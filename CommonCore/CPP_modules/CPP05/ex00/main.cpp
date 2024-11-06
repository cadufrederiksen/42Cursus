/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:59:40 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/06 15:16:41 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureacraut.hpp"

int main ()
{
    try 
    {
        Bureacraut b(10, "John");
        std::cout << b << std::endl;
        b.DecrementGrade(1);
        std::cout << b << std::endl;
        b.IncrementGrade(12);
        std::cout << b << std::endl;
    }
    catch (const Bureacraut::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const Bureacraut::GradeTooHighException& c)
    {
        std::cerr << c.what() << std::endl;
    }
    return 0;
}