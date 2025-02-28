/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:59:50 by ncolomer          #+#    #+#             */
/*   Updated: 2025/02/28 13:29:50 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <vector>
# include "ATarget.hpp"

class TargetGenerator
{
private:
	std::vector<ATarget*> types;//vector com os diferentes tipos
public:
	TargetGenerator();
	virtual ~TargetGenerator();

	//iguais que os spell de warlock.cpp
	void learnTargetType(ATarget *type);//busca um tipo e se encontra adiciona ao vector(copiando)
	void forgetTargetType(std::string const &name);//busca um tipo e se encontra deleta ele
	ATarget *createTarget(std::string const &name);//busca um tipo e se encontra devolve ele
};

#endif
