#include <unistd.h>

void repeat_aplha()
{
	int i;

	i = 0;
}

int main(int argc, char **argv )
{
	int i;
	int x;

	i = 0;
	if(argc == 2)
	{

		while(argv[1][i])
		{
			x = 0;
			if(argv[1][i] >= 65 && argv[1][i] <= 91)
			{
				while(x <= (argv[1][i] - 65))
				{
					write(1, &argv[1][i], 1);
					x++;
				}
			}
			else if(argv[1][i] >= 97 && argv[1][i] <= 122)
			{
				while(x <= argv[1][i] - 97)
				{
					write(1, &argv[1][i], 1);
					x++;
				}
			}
			else 
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);

	

}
