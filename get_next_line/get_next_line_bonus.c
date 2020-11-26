/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:19:42 by imasahir          #+#    #+#             */
/*   Updated: 2020/08/24 23:02:20 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char		*gnl_keep(char *keep, char *tmp)
{
	char *str;

	str = ft_strjoin(keep, tmp);
	free(keep);
	free(tmp);
	return (str);
}

static char		*line_divide(char *keep, int rdint)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = NULL;
	if (rdint > 0)
	{
		while (keep[i] != '\n')
			i++;
		if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		while (j < i)
		{
			str[j] = keep[j];
			j++;
		}
		str[j] = '\0';
	}
	else if (rdint == 0)
		str = ft_strdup(keep);
	return (str);
}

static char		*keep_divide(char *keep, int rdint)
{
	char	*str;
	int		i;

	str = 0;
	i = 0;
	if (rdint > 0)
	{
		while (keep[i] != '\n')
			i++;
		str = ft_strdup(&keep[i + 1]);
	}
	free(keep);
	keep = NULL;
	return (str);
}

int				get_next_line(int fd, char **line)
{
	static char *keep[OPEN_MAX];
	char		*tmp;
	int			rdint;

	rdint = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!keep[fd])
		keep[fd] = ft_strdup("");
	while (ft_strchr(keep[fd], '\n') == NULL && rdint > 0)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		if ((rdint = read(fd, tmp, BUFFER_SIZE)) < 0)
			return (-1);
		tmp[rdint] = '\0';
		keep[fd] = gnl_keep(keep[fd], tmp);
	}
	if (!(*line = line_divide(keep[fd], rdint)))
		return (-1);
	keep[fd] = keep_divide(keep[fd], rdint);
	return (rdint > 0 ? 1 : 0);
}
