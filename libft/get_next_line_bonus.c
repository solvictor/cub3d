/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:22:02 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/19 17:50:21 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_readline(char *str, int *found, int fd);
static char	*ft_has_newline(char *str, int *found);

char	*get_next_line(int fd)
{
	static char	str[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	char		*tmp2;
	int			found;

	found = 0;
	if (fd >= 0 && fd < FOPEN_MAX - 1 && BUFFER_SIZE > 0)
	{
		str[fd][BUFFER_SIZE] = '\0';
		line = ft_has_newline(str[fd], &found);
		while (found == 0)
		{
			tmp = ft_readline(str[fd], &found, fd);
			tmp2 = ft_strjoin_noconst(line, tmp);
			free(line);
			line = ft_strdup_bool(tmp2, 1);
			free(tmp);
		}
		if (line && !line[0])
			return (free(line), NULL);
		return (line);
	}
	return (NULL);
}

char	*ft_readline(char *str, int *found, int fd)
{
	char	*bu;
	int		i;

	bu = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bu)
		return (NULL);
	i = read(fd, bu, BUFFER_SIZE);
	if (i > -1)
	{
		bu[i] = '\0';
		i = 0;
		while (bu[i] && bu[i] != '\n')
			i++;
		*found = ((!bu[0]) || (!bu[i] && i < BUFFER_SIZE) || (bu[i] == '\n'));
		if (bu[i] == '\n')
		{
			ft_strlcpy_noconst(str, bu, BUFFER_SIZE + 1);
			bu[i + 1] = '\0';
		}
		ft_str_clean_nl(str);
		return (bu);
	}
	free(bu);
	*found = 1;
	return (NULL);
}

char	*ft_has_newline(char *str, int *found)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		*found = 1;
	i += *found;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (--i >= 0)
		line[i] = str[i];
	ft_str_clean_nl(str);
	return (line);
}

/*
int main(void)
{
	int 	fd;
	
	char 	*line;
	int		i;

	i = 0;
	fd = open("get_next_line.h", O_RDONLY);
	line = get_next_line(fd);
	printf("LINE%d:\n%s==============\n", i++, line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		printf("LINE%d:\n%s==============\n", i++, line);
	}
	free(line);
	close(fd);
	return(0);
}
*/
