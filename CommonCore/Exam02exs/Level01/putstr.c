#include <unistd.h>

void putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main()
{
	char *array = "hola que tal";
	putstr(array);
}
