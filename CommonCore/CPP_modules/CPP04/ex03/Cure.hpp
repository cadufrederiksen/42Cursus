/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:57:12 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/25 13:01:26 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
    #define CURE_HPP

#include "AMateria.hpp"

class Cure : public Amateria
{
    public:
        Cure(std::string const type);
        Cure(const Cure& orig);
        Cure& operator=(const Cure& orig);
        ~Cure();
};

#endif