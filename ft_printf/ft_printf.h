/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imasahir <imasahir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:31:39 by imasahir          #+#    #+#             */
/*   Updated: 2020/09/05 21:29:18 by imasahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define STDOUT 1
# define ON 1
# define OFF 0
# define SPACE ' '
# define ERROR -1
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_printf
{
	int		zero;
	int		minus;
	int		field;
	int		prec;
	int		error;
	int		len;
	int		null;
	int		negative;
	int		t_zero;
	char	type;
}				t_printf;

int				put_type_c(int c, t_printf *p_info);

void			put_zero_s(int len, t_printf *p_info);
int				put_string_s(char *str, int s_len, t_printf *p_info);
void			put_space_s(int len, t_printf *p_info);
int				put_type_s(char *str, t_printf *p_info);

int				put_digit_id(char *str, int s_len, int len, t_printf *p_info);
int				put_digit_id2(char *str, int s_len, int len, t_printf *p_info);
void			put_space_id(char *str, int s_len, t_printf *p_info);
int				put_type_id(long i, t_printf *p_info);

int				put_space_p(int len, t_printf *p_info);
int				put_pointer(char *str, int len, t_printf *p_info);
int				put_type_p(void *p, t_printf *p_info);

int				put_digit_u(char *str, int s_len, int len, t_printf *p_info);
int				put_digit_u2(char *str, int s_len, int len, t_printf *p_info);
void			put_space_u(char *str, int s_len, t_printf *p_info);
int				put_type_u(unsigned int id, t_printf *p_info);

int				put_digit_x(char *str, int s_len, int len, t_printf *p_info);
int				put_digit_x2(char *str, int s_len, int len, t_printf *p_info);
void			put_space_x(char *str, int s_len, t_printf *p_info);
int				put_type_x(unsigned int id, t_printf *p_info);

void			apply_flag(char **s, t_printf *p_info);
void			apply_field(char **s, va_list list, t_printf *p_info);
void			apply_prec(char **s, va_list list, t_printf *p_info);
void			apply_type(char **s, t_printf *p_info);

int				ft_vprintf(const char *s, va_list list);
int				ft_printf(const char *s, ...);

void			ft_strlower(char *str);
int				ft_putchar_rfd(char c, int fd);
int				ft_putstr_rlen(char *s, int len);
char			*ft_itoa_base(long di, char *base);
void			safe_free(void *p);

#endif
