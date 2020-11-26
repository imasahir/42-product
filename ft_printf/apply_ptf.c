/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ptf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 00:56:13 by imasahir          #+#    #+#             */
/*   Updated: 2020/09/05 15:34:19 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_flag(char **s, t_printf *p_info)
{
	while (ft_strchr("-0", **s))
	{
		if (**s == '0' && !p_info->minus)
			p_info->zero = ON;
		if (**s == '-')
		{
			p_info->minus = ON;
			p_info->zero = OFF;
		}
		(*s)++;
	}
}

void	ap_field_asta(va_list list, t_printf *p_info)
{
	int	tmp;

	tmp = 0;
	tmp = va_arg(list, int);
	if (tmp > 0)
		p_info->field = tmp;
	else
	{
		p_info->minus = ON;
		p_info->zero = OFF;
		p_info->field = -tmp;
	}
}

void	apply_field(char **s, va_list list, t_printf *p_info)
{
	while (**s == '*' || ft_isdigit(**s))
	{
		if (**s == '*')
		{
			ap_field_asta(list, p_info);
			(*s)++;
		}
		else
		{
			while (ft_isdigit(**s))
			{
				p_info->field = (p_info->field * 10) + (**s - '0');
				(*s)++;
			}
		}
	}
}

void	apply_prec(char **s, va_list list, t_printf *p_info)
{
	if (**s == '.')
	{
		(*s)++;
		if (**s == '*')
		{
			p_info->prec = va_arg(list, int);
			(*s)++;
		}
		else
		{
			p_info->prec = 0;
			while (ft_isdigit(**s))
			{
				p_info->prec = (p_info->prec * 10) + (**s - '0');
				(*s)++;
			}
		}
	}
}

void	apply_type(char **s, t_printf *p_info)
{
	if (ft_strchr("cspdiuxX%", **s))
	{
		p_info->type = **s;
		(*s)++;
	}
	else
		p_info->error = 1;
}
