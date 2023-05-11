/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cset_in_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:24:27 by tgernez           #+#    #+#             */
/*   Updated: 2023/01/02 17:27:46 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_cset_in_str(char *charset, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
				return (str[i]);
			j++;
		}
		i++;
	}
	return ('\0');
}
