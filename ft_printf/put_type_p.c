/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 21:23:21 by imasahir          #+#    #+#             */
/*   Updated: 2020/09/05 21:30:40 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				put_space_p(int len, t_printf *p_info)
{
	int			r_int;

	r_int = 0;
	if (p_info->prec >= 0 && p_info->prec > len)
	{
		while (p_info->field-- > p_info->prec)
			r_int += ft_putchar_rfd(SPACE, STDOUT);
	}
	else if (p_info->field > len)
	{
		while (p_info->field-- > len)
			r_int += ft_putchar_rfd(SPACE, STDOUT);
	}
	return (r_int);
}

int				put_pointer(char *str, int len, t_printf *p_info)
{
	int			r_int;
	int			tmp;

	r_int = 0;
	tmp = len;
	if (p_info->prec > len)
	{
		while (p_info->prec-- - tmp)
			r_int += ft_putchar_rfd('0', STDOUT);
	}
	r_int += ft_putstr_rlen(str, len);
	return (r_int);
}

int				put_type_p(void *p, t_printf *p_info)
{
	char		*str;
	int			len;

	len = 0;
	str = ft_itoa_base((long)p, "0123456789abcdef");
	if (p_info->prec != 0 || p)
		len = ft_strlen(str);
	p_info->field -= 2;
	if (p_info->minus)
	{
		p_info->len += ft_putstr_rlen("0x", 2);
		p_info->len += put_pointer(str, len, p_info);
		p_info->len += put_space_p(len, p_info);
	}
	else
	{
		p_info->len += put_space_p(len, p_info);
		p_info->len += ft_putstr_rlen("0x", 2);
		p_info->len += put_pointer(str, len, p_info);
	}
	safe_free(str);
	return (p_info->len);
}
