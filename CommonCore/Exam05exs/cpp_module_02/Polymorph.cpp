/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:49:28 by ncolomer          #+#    #+#             */
/*   Updated: 2025/02/28 13:15:16 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph()://feitico e seuu efeito
	ASpell("Polymorph", "turned to a sheep") {}

Polymorph::~Polymorph() {}
//funcao de clonagem
ASpell *Polymorph::clone(void) const {
	return (new Polymorph(*this));
}
