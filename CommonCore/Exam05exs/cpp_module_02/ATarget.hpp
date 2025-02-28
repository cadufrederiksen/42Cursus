/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 23:06:18 by ncolomer          #+#    #+#             */
/*   Updated: 2025/02/28 13:10:36 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include <string>
//IGUAL O ANTERIOR mas com protected e nao private
class ASpell;

class ATarget
{
protected://protected
	std::string type;
public:
	ATarget();
	ATarget(std::string const &type);
	ATarget(ATarget const &other);
	virtual ~ATarget();

	ATarget &operator=(ATarget const &other);

	std::string const &getType(void) const;

	void getHitBySpell(ASpell const &spell) const;

	virtual ATarget *clone(void) const = 0;
};

# include "ASpell.hpp"

#endif
