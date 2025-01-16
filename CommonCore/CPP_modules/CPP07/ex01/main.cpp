/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:09:06 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/16 15:13:10 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int array[4] = {1, 2, 3, 4};
	std::string strs[3] = {"hola", "que", "tal"};
	
	iter(array, 4, print_iter);
	iter(strs, 3, print_iter);
}