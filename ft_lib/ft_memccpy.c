/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 14:16:10 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/15 20:16:31 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*uc_src;
	void			*re;

	i = 0;
	uc_src = (unsigned char *)src;
	while (i < n)
	{
		((unsigned char *)dest)[i] = uc_src[i];
		if (((unsigned char *)dest)[i] == (unsigned char)c)
		{
			re = &((unsigned char *)dest)[i + 1];
			return (re);
		}
		i++;
	}
	re = NULL;
	return (re);
}
