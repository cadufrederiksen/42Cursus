/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 23:05:57 by ncolomer          #+#    #+#             */
/*   Updated: 2025/02/27 16:44:18 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell():
	name(), effects() {}

ASpell::ASpell(std::string const &name, std::string const &effects):
	name(name), effects(effects) {}

ASpell::ASpell(ASpell const &other):
	name(other.name), effects(other.effects) {}

ASpell::~ASpell() {}

ASpell &ASpell::operator=(ASpell const &other) {
	this->name = other.name;
	this->effects = other.effects;
	return (*this);
}

//getters
std::string const &ASpell::getName(void) const {
	return (this->name);
}

std::string const &ASpell::getEffects(void) const {
	return (this->effects);
}

//funcao launch
void ASpell::launch(ATarget const &target) const {
	target.getHitBySpell(*this);
}
