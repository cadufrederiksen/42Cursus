#include <unistd.h>
#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
	int i; 

	i = 0;
	while(s1 || s2)
	{
		if(s1[i] > s2[i])
			return(s1[i] - s2[i]);
		if(s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int main(void)
{
	printf("%d", ft_strcmp("hola", "holA"));
	return(0);
}
