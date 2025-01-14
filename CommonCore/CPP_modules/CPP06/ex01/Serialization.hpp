/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:39:16 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/14 15:01:20 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
	#define SERIALIZATION_HPP

#include <iostream>

class Serialization
{
	private:
		Serialization();
		Serialization(const Serialization &orig);
		Serialization operator=(const Serialization &orig);
		~Serialization();
	
	public:
		uintptr_t serialize(Data *ptr);
		Data *deserialize(uintptr_t raw);
		
		
		
};

typedef struct t_data{
	
	int num;	
	
} Data;

#endif