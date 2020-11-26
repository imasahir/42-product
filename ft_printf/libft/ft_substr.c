/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 00:26:05 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/15 21:16:49 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	char	*c_s;
	size_t	i;

	i = 0;
	c_s = (char *)s;
	if (s == 0)
		return (0);
	if (start >= ft_strlen(s))
	{
		buf = ft_calloc(1, sizeof(char));
		return (buf);
	}
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (0);
	while (c_s[start + i] != '\0' && i < len)
	{
		buf[i] = c_s[start + i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
