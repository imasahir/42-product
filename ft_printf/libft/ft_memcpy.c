/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:17:15 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/15 20:22:39 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest2;
	unsigned char	*src2;
	void			*re;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dest2 = dest;
	src2 = (unsigned char *)src;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	re = dest2;
	return (re);
}
