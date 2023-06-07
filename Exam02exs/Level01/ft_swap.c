#include <stdio.h>

void ft_swap(int *a, int *b)
{	
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

int main()
{
	int a = 9;
	int b = 0;
	ft_swap(&a, &b);
	printf("%d\n%d", a, b);
}
