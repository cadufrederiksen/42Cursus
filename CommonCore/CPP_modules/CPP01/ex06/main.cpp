/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:13:35 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/02 15:53:31 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.cpp"

int main(int argc, char **argv)
{
	Harl obj;

	if (argc != 2)	
	{
		std::cout << "Wrong number os parameters!" << std::endl;	
		return (1);
	}
	
	obj.complain(argv[1]);
}