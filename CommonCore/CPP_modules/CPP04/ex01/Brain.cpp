/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:25:51 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/23 18:33:50 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &orig)
{
    if(this != &orig)
    {
       for (int x = 0; x < 100; x++)
            this->ideas[x] = orig.ideas[x];
    }
    std::cout << "Brain copy operator called" << std::endl;
    return *this;
}

Brain::Brain(const Brain &orig)
{
    *this = orig;
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destrucot called" << std::endl;
}