/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:53:14 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/14 21:38:04 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long			count_nod(long n)
{
	long		nod;

	nod = 1;
	while (n >= 10)
	{
		n /= 10;
		nod++;
	}
	return (nod);
}

void			assign_num(char *str, long n, int nod)
{
	if (n >= 10)
	{
		str[nod - 1] = (n % 10) + '0';
		assign_num(str, n / 10, nod - 1);
	}
	else
	{
		str[nod - 1] = n + '0';
	}
}

char			*ft_itoa(int n)
{
	char		*str;
	long		nod;
	long		negative;
	long		ln;

	ln = (long)n;
	if (ln < 0)
	{
		negative = 1;
		ln *= -1;
	}
	else
		negative = 0;
	nod = count_nod(ln);
	if (!(str = (char *)malloc(sizeof(char) * (nod + negative + 1))))
		return (NULL);
	assign_num(str, ln, nod + negative);
	if (negative)
		str[0] = '-';
	str[nod + negative] = 0;
	return (str);
}
