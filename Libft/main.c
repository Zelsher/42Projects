#include "libft.h"

//main de test de random sur une sequence de 10000 nombres
//pourcentage de doublons estime : 99.995%

int main()
{
	int i;
	int	seed;
	int	j;
	int doublons;
	long long int	*result;

	i = 0;
	seed = ft_random_seed(0);
	result = malloc(sizeof(int) * 10000);
	while (i < 10000)
	{
		j = 0;
		result[i] = ft_random(seed, 4, 0);
		seed = ft_random_seed(seed);
		ft_printf("Result : %d\n\n", result[i]);
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
	ft_printf("\nDoublons : %d\n", doublons);
	return(0);
}