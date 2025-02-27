/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:37:27 by ncolomer          #+#    #+#             */
/*   Updated: 2025/02/27 15:43:46 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>

class Warlock
{
private:
	std::string name;//var
	std::string title;//var

	Warlock();//construtor padrao
	Warlock(Warlock const &other);//construtor de cópia

	Warlock &operator=(Warlock const &other);//operador de cópia
public:
	Warlock(std::string const &name, std::string const &title);//construtor com parametros
	virtual ~Warlock();//Destrutor virtual

	std::string const &getName(void) const;//getter de nome const
	std::string const &getTitle(void) const;//getter do titulo

	void setTitle(std::string const &title);//setter do titulo

	void introduce(void) const;//funcao com std::cout
};

#endif
