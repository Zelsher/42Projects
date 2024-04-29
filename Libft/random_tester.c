#include "Libft/libft.h"
#include "inc/live_game.h"

int main()
{
	int i;
	int	seed;
	int	j;
	int doublons;
	int	count;
	int	len;
	long long int	*result;

	i = 0;
	len = 10000;
	result = malloc(sizeof(long long int) * len);
	while (i < len)
	{
		j = 0;
		result[i] = RANDOM(len, 0);
		printf("Result : ==%lld==\n____________\n", result[i]);
		while (j != i)
		{
			if (result[j] == result[i])
			{
				doublons++;
				break;
			}
			j++;
		}
		i++;
	}
	i = 0;
	printf("\nDoublons : %d\n", doublons);
	j = 0;
	while (j < len)
	{
		count = 0;
		i = 0;
		while(i < len)
		{
			if (result[i] == j)
				count++;
			i++;
		}
		if (count)
			printf("Caractere %d : %d fois\n", j, count);
		j++;
	}
	return(0);
}