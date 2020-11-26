/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 23:55:05 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/15 21:07:36 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*buf;
	int		len;
	int		i;

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
