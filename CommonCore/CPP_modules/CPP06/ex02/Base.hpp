/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:05:59 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/10 15:34:28 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
	#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
	public:
		virtual ~Base();
		
	Base *generate(void);
	void identify(Base *p);
	void identify(Base &p);
};

#endif