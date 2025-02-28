/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:58:33 by ncolomer          #+#    #+#             */
/*   Updated: 2025/02/28 13:12:08 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

# include "ATarget.hpp"

class BrickWall: public ATarget//derivada 
{
public:
	BrickWall();
	virtual ~BrickWall();
	//metodo de clonagem
	virtual ATarget *clone(void) const;
};

#endif
