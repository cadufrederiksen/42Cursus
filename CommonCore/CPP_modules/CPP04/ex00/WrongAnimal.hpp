/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:44:49 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/21 21:46:22 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
	#define WRONGANIMAL_HPP
	
#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string type;
		
	public:
		WrongAnimal();
		WrongAnimal(std::string);
		WrongAnimal(const WrongAnimal& orig);
		WrongAnimal &operator=(const WrongAnimal&orig);
		virtual ~WrongAnimal();
		
		std::string getType() const;
		virtual void makeSound() const; 
};



#endif