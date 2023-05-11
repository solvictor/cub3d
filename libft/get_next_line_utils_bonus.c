/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:22:14 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/19 17:50:41 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_noconst(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_noconst(char *s1, char *s2)
{
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen_noconst(s1) + ft_strlen_noconst(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str - len);
}

int	ft_str_clean_nl(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		while (str[++i])
		{
			str[j] = str[i];
			j++;
		}
		str[j] = '\0';
		return (1);
	}
	str[0] = '\0';
	return (-1);
}

char	*ft_strdup_bool(char *s1, int malloced)
{
	size_t	i;
	size_t	len;
	char	*dest;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	dest = malloc(sizeof (char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	if (malloced)
		free(s1);
	return (dest);
}

size_t	ft_strlcpy_noconst(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;

	len_src = ft_strlen_noconst(src);
	i = 0;
	if (dstsize == 0)
		return (len_src);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}
