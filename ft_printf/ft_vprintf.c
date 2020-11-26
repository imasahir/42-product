/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 00:57:49 by imasahir          #+#    #+#             */
/*   Updated: 2020/09/05 21:02:36 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		reset_t(t_printf *p_info)
{
	p_info->type = '\0';
	p_info->zero = OFF;
	p_info->minus = OFF;
	p_info->field = 0;
	p_info->prec = -1;
	p_info->null = OFF;
	p_info->error = OFF;
	p_info->negative = OFF;
	p_info->t_zero = OFF;
	p_info->len = 0;
}

static void		apply_info(char **s, va_list list, t_printf *p_info)
{
	apply_flag(s, p_info);
	apply_field(s, list, p_info);
	apply_prec(s, list, p_info);
	apply_type(s, p_info);
}

static int		after_per(const char **s, va_list list, t_printf *p_info)
{
	reset_t(p_info);
	apply_info((char **)s, list, p_info);
	if (p_info->error == ON)
		return (ERROR);
	if (p_info->type == 'c')
		return (put_type_c(va_arg(list, int), p_info));
	else if (p_info->type == 's')
		return (put_type_s(va_arg(list, char*), p_info));
	else if (p_info->type == 'p')
		return (put_type_p(va_arg(list, void *), p_info));
	else if (p_info->type == 'i' || p_info->type == 'd')
		return (put_type_id((long)va_arg(list, int), p_info));
	else if (p_info->type == 'u')
		return (put_type_u(va_arg(list, unsigned int), p_info));
	else if (p_info->type == 'x' || p_info->type == 'X')
		return (put_type_x(va_arg(list, unsigned int), p_info));
	else if (p_info->type == '%')
		return (put_type_c('%', p_info));
	return (ERROR);
}

int				ft_vprintf(const char *s, va_list list)
{
	t_printf	info;
	int			tmp;
	int			len;

	tmp = 0;
	len = 0;
	while (*s)
	{
		if (*s != '%')
			len += ft_putchar_rfd(*s++, STDOUT);
		else if (*s == '%')
		{
			s++;
			if ((tmp = after_per(&s, list, &info)) < 0)
				return (ERROR);
			len += tmp;
		}
	}
	return (len);
}
