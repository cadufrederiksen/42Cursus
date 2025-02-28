/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:51:10 by ncolomer          #+#    #+#             */
/*   Updated: 2025/02/28 13:23:12 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <vector>
# include "ASpell.hpp"
//parecido com Warlock do ex anterior
class SpellBook
{
private://vector de spell
	std::vector<ASpell*> spells;

	SpellBook(SpellBook const &other);//construtor metodo canonico
	SpellBook &operator=(SpellBook const &other);
public:
	SpellBook();
	virtual ~SpellBook();

	void learnSpell(ASpell *spell);//igual warlock.cpp
	void forgetSpell(std::string const &spellName);//igual warlock.cpp
	ASpell *generateSpell(std::string const &spellName);//procura um feitico e devolve ele se encontra
};

#endif
