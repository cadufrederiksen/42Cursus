/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:49:03 by ncolomer          #+#    #+#             */
/*   Updated: 2025/02/28 13:14:14 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball()://feitico e seu efeito
	ASpell("Fireball", "burnt to a crisp") {}

Fireball::~Fireball() {}
//novo Fireball
ASpell *Fireball::clone(void) const {
	return (new Fireball(*this));
}
