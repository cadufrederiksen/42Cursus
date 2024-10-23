/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:39:53 by carmarqu          #+#    #+#             */
/*   Updated: 2024/10/23 18:25:43 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
    #define BRAIN_HPP

#include "Animal.hpp"

class Brain {

    private:
        std::string ideas[100];
        
    public:
        Brain();
        Brain(const Brain &orig);
        Brain &operator=(const Brain &orig);
        ~Brain();
};

#endif