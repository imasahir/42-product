/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:10:47 by imasahir          #+#    #+#             */
/*   Updated: 2020/09/05 21:31:46 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				put_type_c(int c, t_printf *p_info)
{
	if (p_info->minus)
	{
		p_info->len += ft_putchar_rfd(c, STDOUT);
		if (p_info->field != 0)
		{
			while (--p_info->field)
				p_info->len += ft_putchar_rfd(SPACE, STDOUT);
		}
	}
	else
	{
		if (p_info->zero && p_info->field)
		{
			while (--p_info->field)
				p_info->len += ft_putchar_rfd('0', STDOUT);
		}
		else if (p_info->field != 0)
		{
			while (--p_info->field)
				p_info->len += ft_putchar_rfd(SPACE, STDOUT);
		}
		p_info->len += ft_putchar_rfd(c, STDOUT);
	}
	return (p_info->len);
}

void			put_space_s(int len, t_printf *p_info)
{
	int			i;

	i = 0;
	if (p_info->zero == ON)
		return ;
	if (p_info->zero == OFF && p_info->field > len)
	{
		while (i < (p_info->field - len))
		{
			p_info->len += ft_putchar_rfd(SPACE, STDOUT);
			i++;
		}
	}
}

void			put_zero_s(int len, t_printf *p_info)
{
	int			i;

	i = 0;
	if (p_info->zero == ON && p_info->field > len)
	{
		while (i < (p_info->field - len))
		{
			p_info->len += ft_putchar_rfd('0', STDOUT);
			i++;
		}
	}
}

int				put_string_s(char *str, int s_len, t_printf *p_info)
{
	if (p_info->minus)
	{
		p_info->len += ft_putstr_rlen(str, s_len);
		put_space_s(s_len, p_info);
	}
	else
	{
		put_space_s(s_len, p_info);
		put_zero_s(s_len, p_info);
		p_info->len += ft_putstr_rlen(str, s_len);
	}
	return (p_info->len);
}

int				put_type_s(char *str, t_printf *p_info)
{
	int			len;
	int			s_len;

	if (!str)
	{
		if (!(str = ft_strdup("(null)")))
			return (ERROR);
		p_info->null = ON;
	}
	len = ft_strlen(str);
	s_len = 0;
	if (p_info->prec >= 0 && len > p_info->prec)
		s_len = p_info->prec;
	else
		s_len = len;
	put_string_s(str, s_len, p_info);
	if (p_info->null == ON)
		safe_free(str);
	return (p_info->len);
}
