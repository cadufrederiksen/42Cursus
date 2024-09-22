/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:21:24 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/20 19:58:02 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char** argv)
{
    int i;
    int x;

    x = 1;
    if (!argv[x])
        std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE";
    while (argv[x])
    {
        i = 0;
        while (argv[x][i])
        {
            std::cout << (char)toupper(argv[x][i]);
            i++;
        }
        std::cout << " ";
        x++;
    }
    std::cout << std::endl;
    return (0);
}
