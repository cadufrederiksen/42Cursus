/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:59:17 by ncolomer          #+#    #+#             */
/*   Updated: 2025/02/28 13:13:34 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"
//alvo
BrickWall::BrickWall():
	ATarget("BrickWall Practice") {}

BrickWall::~BrickWall() {}

ATarget *BrickWall::clone(void) const {//cria um novo Brickwall
	return (new BrickWall(*this));
}
