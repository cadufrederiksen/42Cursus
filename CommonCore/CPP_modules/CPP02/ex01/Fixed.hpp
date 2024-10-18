/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:43:54 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/05 18:27:29 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
	#define FIXED_HPP

#include <iostream>	
#include <cmath>	

class Fixed
{
	private:
		int fixedPointValue;
		static const int fractionalBits = 8;
		
	public:
		Fixed();
		Fixed(const int x);
		Fixed(const float y);
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& copy);//define = como um operador para copiar objetos
		~Fixed();

		int getRawBits (void) const;
		void setRawBits (int const raw);
		
		float	toFloat (void) const;
		int		toInt	(void) const;
		
};

	std::ostream &operator<<(std::ostream &os, const Fixed &obj);
#endif