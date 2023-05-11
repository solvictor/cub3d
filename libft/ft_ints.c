/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ints.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:42:19 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/21 15:50:12 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_ints(int len_tab, int len_tabs)
{
	int	i;
	int	**tab;

	tab = malloc(sizeof(int *) * (len_tab + 1));
	if (!tab)
		return (NULL);
	tab[len_tab] = NULL;
	i = 0;
	while (i < len_tab)
	{
		tab[i] = malloc(sizeof(int) * len_tabs);
		if (!tab[i])
			return (ft_free_ints(tab), NULL);
		i++;
	}
	return (tab);
}
