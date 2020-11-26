/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:55:38 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/15 20:59:48 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return (char *)str;
	i = 0;
	while (i < len && str[i] != '\0')
	{
		j = 0;
		if (str[i] == needle[j])
		{
			while (str[i + j] == needle[j] && i + j < len)
			{
				j++;
				if (needle[j] == '\0')
					return (&((char *)str)[i]);
			}
		}
		i++;
	}
	return (NULL);
}
