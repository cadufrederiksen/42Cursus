/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 23:26:40 by ncolomer          #+#    #+#             */
/*   Updated: 2025/02/27 16:54:57 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget():
	type() {}

ATarget::ATarget(std::string const &type):
	type(type) {}

ATarget::ATarget(ATarget const &other):
	type(other.type) {}

ATarget::~ATarget() {}

ATarget &ATarget::operator=(ATarget const &other) {
	this->type = other.type;
	return (*this);
}

//getter
std::string const &ATarget::getType(void) const {
	return (this->type);
}

//imprime a frase e mostra o efeito do feitiço com getEffects()
void ATarget::getHitBySpell(ASpell const &spell) const {
	std::cout << this->type << " has been " << spell.getEffects() << "!\n";
}
