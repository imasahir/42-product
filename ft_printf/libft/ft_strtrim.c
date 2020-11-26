/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:08:31 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/15 21:59:47 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_set(char s, char *set)
{
	int			i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

static int		count_begining(char *s1, char *set)
{
	int			i;

	i = 0;
	while (check_set(s1[i], set))
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (i);
}

static int		count_end(char *s1, char *set)
{
	int			i;
	int			len;

	i = 1;
	len = ft_strlen(s1);
	while (check_set(s1[len - i], set))
	{
		if (len - i < 0)
			return (0);
		i++;
	}
	return (i - 1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*buf;
	int			i;
	int			len;
	int			begining;
	int			end;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	begining = count_begining((char *)s1, (char *)set);
	if (begining == (int)ft_strlen(s1))
		return (ft_strdup(""));
	end = count_end((char *)s1, (char *)set);
	len = ft_strlen(s1) - begining - end;
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (0);
	while (i < len)
	{
		buf[i] = s1[begining + i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
