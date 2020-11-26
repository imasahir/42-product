/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:19:44 by imasahir          #+#    #+#             */
/*   Updated: 2020/08/24 22:52:15 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(const char *s)
{
	size_t		len;
	char		*c_s;

	len = 0;
	c_s = (char *)s;
	while (c_s[len] != '\0')
		len++;
	return (len);
}

char			*ft_strchr(const char *s, int c)
{
	int			i;
	char		*cc_s;
	char		*tmp;

	i = 0;
	cc_s = (char *)s;
	while (cc_s[i] != '\0')
	{
		if (cc_s[i] == (unsigned char)c)
		{
			tmp = &cc_s[i];
			return (tmp);
		}
		i++;
	}
	if (cc_s[i] == (unsigned char)c)
	{
		tmp = &cc_s[i];
		return (tmp);
	}
	return (NULL);
}

char			*ft_strdup(const char *s)
{
	char		*buf;
	int			len;
	int			i;

	i = 0;
	len = ft_strlen(s);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (0);
	while (s[i] != '\0')
	{
		buf[i] = s[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*buf;
	int			i;
	int			len_s1;
	int			len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	if (!(buf = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		buf[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		buf[i + len_s1] = s2[i];
		i++;
	}
	buf[i + len_s1] = '\0';
	return (buf);
}
