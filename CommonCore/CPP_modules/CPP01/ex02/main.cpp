/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:03:22 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 15:10:15 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str; //criacao do ponteiro
	
	std::string& ref = str; //criacao da referencia
	
	std::cout << &str << std::endl;//endereço str
	std::cout << str << std::endl;//valor str
	std::cout << ptr << std::endl;//endereço ptr
	std::cout << *ptr << std::endl;//valor ptr
	std::cout << &ref << std::endl;//endereço ref
	std::cout << ref << std::endl;//valor ref
}