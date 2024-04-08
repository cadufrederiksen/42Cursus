/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:57:14 by carmarqu          #+#    #+#             */
/*   Updated: 2023/06/05 16:08:50 by carmarq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void first_word (char *s)
{
	int i;

	i = 0;
	while(s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	while(s[i] != 32)
	{
		if (s[i + 1] == 32 || (s[i + 1] >= 9 && s[i + 1] <= 13))
		{
			write(1, &s[i], 1);
			return ;
		}	
			write(1, &s[i], 1);	
			i++;
	}
}

int main(int argc, char **argv)
{
	if(argc != 2)
		return 0;
	else
	{	
		first_word(argv[1]);
		write(1, "\n", 1);
	}
	return 0;
}

