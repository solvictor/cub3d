#include "cub3d_bonus.h"

void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_double(double *a, double *b)
{
	double	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_sprites(int *order, double *dist, int amount)
{
	int	i;
	int	j;

	i = 0;
	while (++i < amount)
	{
		j = -1;
		while (++j < amount - i)
		{
			if (dist[j] < dist[j + 1])
			{
				swap_double(&dist[j], &dist[j + 1]);
				swap_int(&order[j], &order[j + 1]);
			}
		}
	}
}
