#include <unistd.h>

int ft_strlen(char* std)
{
	int i = 0;
	while(std[i])
		i++;
	return i;
}

int main(int ac, char** av)
{
	if(ac == 2)
	{
		int len = ft_strlen(av[1]);
		len--;
		while(av[1][len])
		{
			write(1, &av[1][len], 1);
			len--;
		}
	}

	write(1,"\n",1);
}
