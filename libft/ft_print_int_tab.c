/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:21:58 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/09 11:01:07 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_tab(int *tab, size_t len)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	ft_printf("[");
	while (i < len - 1)
	{
		ft_printf("%d, ", tab[i]);
		i++;
	}
	ft_printf("%d]", tab[i]);
}
