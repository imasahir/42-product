/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:40:28 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/16 00:12:18 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long long	integer;
	int			i;
	int			minus;

	integer = 0;
	i = 0;
	minus = 0;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\f'\
			|| str[i] == '\v' || str[i] == ' ' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		integer = integer * 10 + (str[i] - '0');
		i++;
	}
	if (minus % 2 == 1)
		integer *= -1;
	return (int)integer;
}
