/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:40:29 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/16 14:15:59 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main ()
{
	Base *obj= obj->generate();
	Base *null = NULL;
	obj->identify(obj);
	obj->identify(*obj);
	obj->identify(null);
	obj->identify(*null);
	delete obj;
	return 0;
}