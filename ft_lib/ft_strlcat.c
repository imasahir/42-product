/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 22:47:14 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/15 21:57:24 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_s;
	size_t	dst_s;
	char	*uc_dst;
	char	*uc_src;

	src_s = 0;
	dst_s = 0;
	uc_dst = (char *)dst;
	uc_src = (char *)src;
	while (uc_src[src_s])
		src_s++;
	while (uc_dst[dst_s])
		dst_s++;
	if (dstsize <= dst_s)
		return (dstsize + src_s);
	i = 0;
	while (dstsize && --dstsize - dst_s && uc_src[i])
	{
		uc_dst[dst_s + i] = uc_src[i];
		i++;
	}
	uc_dst[dst_s + i] = '\0';
	return (src_s + dst_s);
}
