/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:03:16 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/23 19:07:47 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
    #define AMATERIA_HPP

#include <iostream>

class Amateria{
    
    protected:
        std::string type;
        
    public:
        Amateria(std::string const &type);
        
        std::string const &getType() const;
        virtual Amateria* clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif

