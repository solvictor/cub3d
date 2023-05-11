/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:40:17 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/21 15:49:30 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_rev_int_tab(int *tab, size_t len)
{
	int		tmp;
	size_t	i;

	i = 0;
	while (i < len / 2)
	{
		tmp = tab[i];
		tab[i] = tab[len - i - 1];
		tab[len - i - 1] = tmp;
		i++;
	}
	return (tab);
}
