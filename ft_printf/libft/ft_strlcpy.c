/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:19:28 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/15 21:56:36 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	char	*uc_dst;
	char	*uc_src;

	j = 0;
	uc_dst = dst;
	uc_src = (char *)src;
	if (dst == 0)
		return (0);
	while (uc_src[j] != 0)
		j++;
	if (dstsize == 0)
		return (j);
	i = 0;
	while (uc_src[i] && i < dstsize - 1)
	{
		uc_dst[i] = uc_src[i];
		i++;
	}
	uc_dst[i] = '\0';
	return (j);
}
