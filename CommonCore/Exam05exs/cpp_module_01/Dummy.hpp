/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 23:06:26 by ncolomer          #+#    #+#             */
/*   Updated: 2025/02/27 16:57:10 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"

class Dummy: public ATarget
{
public:
	Dummy(); //construtor e destrutor
	virtual ~Dummy();

	//funçao para clonar
	virtual ATarget *clone(void) const;
};

#endif
