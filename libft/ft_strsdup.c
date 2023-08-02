/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:13:26 by tgernez           #+#    #+#             */
/*   Updated: 2023/08/02 17:21:09 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsdup(const char **src)
{
	char	**strs;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i])
		++i;
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	strs[i] = NULL;
	i = 0;
	while (src[i])
	{
		strs[i] = ft_strdup(src[i]);
		if (!strs[i])
			return (ft_free_strs(strs), NULL);
		++i;
	}
	return (strs);
}
