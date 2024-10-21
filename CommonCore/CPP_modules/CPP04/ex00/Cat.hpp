/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:29:01 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/21 20:43:03 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
	#define CAT_HPP
	
#include "Animal.hpp"
	
class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& orig);
		Cat& operator=(const Cat& orig);
		virtual ~Cat();
		
		void makeSound() const;
};
	
#endif
