#include "cub3d_bonus.h"

bool	is_line_empty(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_c_in_str(line[i], SPACES))
			return (false);
		++i;
	}
	return (true);
}
