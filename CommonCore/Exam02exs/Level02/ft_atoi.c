#include <stdio.h>
#include <unistd.h>

int ft_atoi(char *str)
{
	int i = 0;
	int neg = 1;
	int result = 0;

	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while(str[i] == '-' || str[i] == '+')
	{
		if(str[i == '-'])
			neg *= -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		if(str[i + 1] < '0' || str[i + 1] > '9')
			return(result *= neg);
		i++;	
	}	
	return(0);
}