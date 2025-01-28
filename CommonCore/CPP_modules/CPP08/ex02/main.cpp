/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:42:50 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/28 14:29:47 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> stack;
	
	stack.push(734);
	stack.push(33);
	stack.push(3313);
	stack.push(231);
	stack.push(11);
	
	for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}