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

int	main(int argc, char **argv)
{
	int a;
	int b;
	int result;

	if (argc == 4)	
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		result = 0;
		if (argv[2][0] == '+')
			result = a + b;
		if (argv[2][0] == '-')
			result = a - b;
		if (argv[2][0] == '*')
			printf("%d", ft_atoi(argv[1]) * ft_atoi(argv[3]));
		if (argv [2][0] == '/')
			result = a / b;
		if (argv[2][0] == '%')
			result = a % b;	
		printf("%d", result);
	}
	write(1, "\n", 1);
	return 0;
}

