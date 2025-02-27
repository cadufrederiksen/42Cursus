/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 23:24:08 by ncolomer          #+#    #+#             */
/*   Updated: 2025/02/27 17:01:08 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh(): //derivado de ASpell
	ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh() {}

//devolve novo fwoosh
ASpell *Fwoosh::clone(void) const {
	return (new Fwoosh(*this)); //construtor de cópia 
}
