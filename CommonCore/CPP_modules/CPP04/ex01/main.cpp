/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:19:46 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/23 18:12:33 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal *animals[4];
    for (int x = 0; x < 4; x++)
    {
        if (x % 2 == 0)
            animals[x] = new Dog();
        else
            animals[x] = new Cat();
    }
    
    for (int x = 0; x < 4; x++)
        animals[x]->makeSound();
        
    for (int x = 3; x >= 0; x--)
        delete animals[x];
}
