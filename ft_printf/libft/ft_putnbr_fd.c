/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:58:35 by imasahir          #+#    #+#             */
/*   Updated: 2020/07/15 22:00:12 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		put_long(long ln, int fd)
{
	long		pl;
	char		pl_char;

	pl = ln % 10;
	pl_char = '0' + pl;
	if (ln >= 10)
		put_long(ln / 10, fd);
	ft_putchar_fd(pl_char, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	long		ln;

	ln = (long)n;
	if (fd < 0)
		return ;
	if (ln == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	put_long(ln, fd);
}
