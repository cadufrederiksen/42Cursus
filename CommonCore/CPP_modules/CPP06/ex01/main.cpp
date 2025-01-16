/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:42:35 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/16 13:04:53 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main()
{
	Data data;
	data.num = 42;
	
	uintptr_t nbr = Serialization::serialize(&data);
	std::cout << "Serialized value: " << nbr << std::endl;
	
	Data *ptr = Serialization::deserialize(nbr);
	std::cout << "Deserialized value: " << ptr << std::endl;
	
}