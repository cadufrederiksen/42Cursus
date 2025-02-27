/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 23:06:34 by ncolomer          #+#    #+#             */
/*   Updated: 2025/02/27 17:11:25 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include "ASpell.hpp"
//IGUAL O ANTERIOR
class Fwoosh: public ASpell
{
public:
	Fwoosh();
	virtual ~Fwoosh();

	virtual ASpell *clone(void) const;
};

#endif
