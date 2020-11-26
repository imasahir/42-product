/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 00:30:13 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/22 10:00:18 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*allfree(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static int		count_arraybase(char *s, char c)
{
	int			count;
	int			i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i++;
			continue;
		}
		count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static char		*sp_strdup(char *s, int len)
{
	char		*tmp;
	int			index;

	if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	index = 0;
	while (index < len)
	{
		tmp[index] = s[index];
		index++;
	}
	tmp[index] = '\0';
	return (tmp);
}

static char		**ft_split_(char **array, char *s, char c, int s_i)
{
	int			i;
	int			arr_i;

	arr_i = 0;
	while (s[s_i])
	{
		if (s[s_i] == c)
		{
			s_i++;
			continue;
		}
		i = 0;
		while (s[s_i + i] != c && s[s_i + i])
			i++;
		if (!(array[arr_i] = sp_strdup(&s[s_i], i)))
			return (allfree(array));
		s_i += i;
		arr_i++;
	}
	array[arr_i] = NULL;
	return (array);
}

char			**ft_split(char const *s, char c)
{
	int			n;
	char		**array;

	if (!s)
		return (NULL);
	n = count_arraybase((char *)s, c);
	if (!(array = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	return (ft_split_(array, (char *)s, c, 0));
}
