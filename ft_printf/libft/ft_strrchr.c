/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 23:40:38 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/15 21:00:21 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s1, int c)
{
	int		i;
	char	*cc_s1;
	char	*tmp;

	i = ft_strlen((char *)s1);
	cc_s1 = (char *)s1;
	while (i >= 0)
	{
		if (cc_s1[i] == c)
		{
			tmp = &cc_s1[i];
			return (tmp);
		}
		i--;
	}
	return (NULL);
}
