/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:33:03 by imasahir          #+#    #+#             */
/*   Updated: 2020/09/05 21:31:22 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			put_space_u(char *str, int s_len, t_printf *p_info)
{
	int			i;

	i = 0;
	if (p_info->zero && p_info->prec < 0)
		return ;
	while (i < (p_info->field - s_len))
	{
		p_info->len += ft_putchar_rfd(SPACE, STDOUT);
		i++;
	}
	if (p_info->prec == 0 && str[0] == '0' && p_info->field > 0)
		p_info->len += ft_putchar_rfd(SPACE, STDOUT);
	if (i < 0)
		return ;
}

int				put_digit_u2(char *str, int s_len, int len, t_printf *p_info)
{
	int			rint;
	int			i;

	rint = 0;
	i = 0;
	if (p_info->prec == 0 && p_info->t_zero == ON)
		return (0);
	if (p_info->negative == ON)
		rint += ft_putchar_rfd('-', STDOUT);
	if (p_info->zero && p_info->prec < 0)
	{
		while (i++ < p_info->field - s_len)
			rint += ft_putchar_rfd('0', STDOUT);
	}
	if (p_info->prec > 0)
	{
		while (i++ < p_info->prec - len)
			rint += ft_putchar_rfd('0', STDOUT);
	}
	rint += ft_putstr_rlen(str, len);
	return (rint);
}

int				put_digit_u(char *str, int s_len, int len, t_printf *p_info)
{
	if (p_info->minus == ON)
	{
		p_info->len += put_digit_u2(str, s_len, len, p_info);
		if (p_info->field > p_info->prec)
			put_space_u(str, s_len, p_info);
	}
	else
	{
		put_space_u(str, s_len, p_info);
		p_info->len += put_digit_u2(str, s_len, len, p_info);
	}
	return (p_info->len);
}

int				put_type_u(unsigned int id, t_printf *p_info)
{
	char		*str;
	int			len;
	int			s_len;

	if (id == 0)
		p_info->t_zero = ON;
	if (id < 0)
	{
		p_info->negative = ON;
		id *= -1;
	}
	if (!(str = ft_itoa_base(id, "0123456789")))
		return (ERROR);
	len = ft_strlen(str);
	if (p_info->prec >= 0 && p_info->prec > len)
		s_len = p_info->prec + p_info->negative;
	else
		s_len = len + p_info->negative;
	put_digit_u(str, s_len, len, p_info);
	safe_free(str);
	return (p_info->len);
}
