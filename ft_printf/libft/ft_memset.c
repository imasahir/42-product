/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 01:48:54 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/15 20:53:48 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <string.h>

void		*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*s2;
	void	*re;

	i = 0;
	s2 = (char *)s;
	while (i < n)
	{
		s2[i] = c;
		i++;
	}
	re = s2;
	return (re);
}
