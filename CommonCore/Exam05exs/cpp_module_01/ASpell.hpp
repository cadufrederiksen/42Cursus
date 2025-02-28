/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 23:06:00 by ncolomer          #+#    #+#             */
/*   Updated: 2025/02/28 13:09:35 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include <string>

class ATarget;

class ASpell
{
private:
	std::string name; //var
	std::string effects; //var
public:
	ASpell(); //metódo canonico
	ASpell(std::string const &name, std::string const &effects);//construtor com parametros
	ASpell(ASpell const &other);
	virtual ~ASpell();//destrutor virtual

	ASpell &operator=(ASpell const &other);

	std::string const &getName(void) const; //getters
	std::string const &getEffects(void) const;

	//funcao para lançar feitiço
	void launch(ATarget const &target) const;

	//metodo puro
	virtual ASpell *clone(void) const = 0;
};

# include "ATarget.hpp"

#endif
