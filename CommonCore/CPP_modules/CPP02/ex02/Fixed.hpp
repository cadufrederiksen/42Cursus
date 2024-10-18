/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:43:54 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/05 22:40:04 by carmarqu         ###   ########.fr       */
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
		
				
		bool operator<(const Fixed& fxd) const;
		bool operator<=(const Fixed& fxd) const;
		bool operator>(const Fixed& fxd) const;
		bool operator>=(const Fixed& fxd) const;
		bool operator==(const Fixed& fxd) const;
		bool operator!=(const Fixed& fxd) const;
		
		Fixed operator+(const Fixed &fxd) const;
		Fixed operator-(const Fixed &fxd) const;
		Fixed operator*(const Fixed &fxd) const;
		Fixed operator/(const Fixed &fxd) const;
		
		Fixed &operator++(void);//prefixo
		Fixed operator++(int);//pósfixo
		Fixed &operator--(void);//prefixo
		Fixed operator--(int);//pósfixo
		
		static Fixed &min(Fixed &a, Fixed &b);
		const static Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		const static Fixed &max(const Fixed &a, const Fixed &b);
};

	std::ostream &operator<<(std::ostream &os, const Fixed &obj);
	
#endif