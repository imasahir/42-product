/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 23:02:48 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/15 21:47:46 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*cc_s;
	char	*tmp;

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
