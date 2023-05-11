/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:38:02 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/21 15:49:12 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_lst(t_list *head)
{
	t_list	*ptr;
	t_list	*tmp;

	if (!head)
		return ;
	ptr = head;
	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
		tmp = NULL;
	}
	head = NULL;
}
