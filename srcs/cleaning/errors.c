#include "cub3d.h"

void	error_str(char *str)
{
	if (!str || str[0] == '\0')
		return ;
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}
