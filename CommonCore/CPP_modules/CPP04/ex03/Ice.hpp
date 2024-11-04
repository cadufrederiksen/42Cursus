/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:01:35 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/25 13:04:43 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
	#define ICE_HPP

#include "AMateria.hpp"

class Ice : public Amateria
{
	public:
		Ice(std::string const type);
		Ice(const Ice& orig);
		Ice& operator=(const Ice& orig);
		~Ice();
};

#endif