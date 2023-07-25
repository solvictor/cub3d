/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_bool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:24:43 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:24:44 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	is_digit_or_point(char c, int *point_count)
{
	if (c == '.')
		(*point_count)++;
	else if (!ft_isdigit(c))
		return (false);
	if (*point_count > 1)
		return (false);
	return (true);
}

static bool	is_valid(const char *str)
{
	int	point_count;

	point_count = 0;
	if (*str == '-')
		str++;
	else if (*str == '+')
		str++;
	while (*str)
		if (!is_digit_or_point(*str++, &point_count))
			return (false);
	return (true);
}

static double	convert_to_double(const char **str, double scale)
{
	double	res;

	res = 0.0;
	while (ft_isdigit(**str))
	{
		res = res * 10.0 + (**str - '0');
		(*str)++;
	}
	return (res / scale);
}

double	ft_atof(const char *str, bool *success)
{
	double	res;
	int		sign;

	sign = 1;
	*success = is_valid(str);
	if (!(*success))
		return (0);
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	res = convert_to_double(&str, 1.0);
	if (*str == '.')
		str++;
	res += convert_to_double(&str, 10.0);
	return (sign * res);
}
