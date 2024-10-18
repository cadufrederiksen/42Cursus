/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:06:20 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/04 16:31:39 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
	#define FIXED_HPP

#include <iostream>	

class Fixed
{
	private:
		int fixedPointValue;
		static const int fractionalBits = 8;
		
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& copy);//define = como um operador para copiar objetos
		~Fixed();

		int getRawBits (void) const;
		void setRawBits (int const raw);
};

#endif