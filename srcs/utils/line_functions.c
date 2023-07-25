/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:23:18 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:23:19 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
