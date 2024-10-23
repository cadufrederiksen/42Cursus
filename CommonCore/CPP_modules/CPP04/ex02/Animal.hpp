/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:43:52 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/23 18:50:15 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPHISM_HPP
	#define POLYMORPHISM_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;
		Animal();
		Animal(std::string);	

	public:	
		Animal(const Animal& orig);
		Animal &operator=(const Animal&orig);
		virtual ~Animal();
		
		std::string getType() const;
		virtual void makeSound() const; 
};

#endif