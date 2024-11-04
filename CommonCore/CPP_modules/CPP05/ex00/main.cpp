/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:59:40 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/04 18:52:37 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureacraut.hpp"

int main ()
{
    try 
    {
        Bureacraut b(150 + 1, "John");
    }
    catch (const Bureacraut::GradeTooLowException& e)
    {
        std::cerr << e.what();
    }
    catch (const Bureacraut::GradeTooHighException& c)
    {
        std::cerr << c.what();
    }
}