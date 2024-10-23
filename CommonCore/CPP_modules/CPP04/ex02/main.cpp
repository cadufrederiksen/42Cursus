/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:19:46 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/23 18:52:59 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    //Animal meta;
    Dog i;
    Cat j;
    std::cout << j.getType() << " " << std::endl;
    std::cout << i.getType() << " " << std::endl;
    i.makeSound(); //will output the cat sound!
    j.makeSound();
   // meta->makeSound();
    
    //delete meta;
    return 0;
}
