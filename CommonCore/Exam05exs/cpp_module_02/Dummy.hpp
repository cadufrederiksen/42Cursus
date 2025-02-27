/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 23:06:26 by ncolomer          #+#    #+#             */
/*   Updated: 2025/02/27 17:10:38 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"
//IGUAL O ANTERIOR
class Dummy: public ATarget
{
public:
	Dummy();
	virtual ~Dummy();

	virtual ATarget *clone(void) const;
};

#endif
