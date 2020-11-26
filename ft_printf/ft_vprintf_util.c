/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 23:58:04 by imasahir          #+#    #+#             */
/*   Updated: 2020/09/05 20:34:20 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_strlower(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

int			ft_putchar_rfd(char c, int fd)
{
	if (fd < 0)
		return (0);
	write(fd, &c, 1);
	return (fd);
}

int			ft_putstr_rlen(char *s, int len)
{
	int		i;

	i = 0;
	if (len < 0 || !s)
		return (0);
	while (*s != '\0' && i < len)
	{
		ft_putchar_fd(*(s++), STDOUT);
		i++;
	}
	return (len);
}

char		*ft_itoa_base(long di, char *base)
{
	long	negative;
	long	b_num;
	long	tmp;
	long	i;
	char	*str;

	negative = 0;
	i = 1;
	if ((tmp = di) < 0)
	{
		negative = i++;
		di *= -1;
	}
	b_num = ft_strlen(base);
	while (tmp /= b_num)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	str[i--] = base[di % b_num];
	while (di /= b_num)
		str[i--] = base[di % b_num];
	if (negative)
		str[i] = '-';
	return (str);
}

void		safe_free(void *p)
{
	free(p);
	p = NULL;
}
