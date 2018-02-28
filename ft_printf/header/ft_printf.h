/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/18 12:18:59 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/25 21:19:38 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
# define MAX(a,b)    b & ((a - b) >> 31) | a & (~(a - b) >> 31)

typedef enum		e_modif
{
	null,
	hh,
	h,
	l,
	ll,
	j,
	z
}					t_modif;

typedef struct		s_flags
{
	t_modif		modif;
	int			width;
	int			size;
	char		type;
	unsigned	hashtag : 1;
	unsigned	zero : 1;
	unsigned	less : 1;
	unsigned	more : 1;
	unsigned	space : 1;
	unsigned	prec : 1;
}					t_flags;

int					ft_printf(const char *format, ...);
int					pf_str(char **format, char **str, int len);
int					pf_special(char **format, va_list ap, char **str, int len);
int					pf_flags(char **format, t_flags *flags);
int					pf_d(va_list ap, t_flags *flags, char **str, int len);
int					pf_u(va_list ap, t_flags *flags, char **str, int len);
int					pf_s(va_list ap, t_flags *flags, char **str, int len);
int					pf_upper_s(va_list ap, t_flags *flags, char **str, int len);
int					pf_c(va_list ap, t_flags *flags, char **str, int len);
int					pf_no(t_flags *flags, char **str, int len, char **format);
int					pf_p(va_list ap, t_flags *flags, char **str, int len);
int					pf_upper_c(va_list ap, t_flags *flags, char **str, int len);
int					pf_base(va_list ap, t_flags *flags, char **str, int len);
int					pf_percent(t_flags *flags, char **str, int len);
char				*pf_litoa_base(long n, char *base);
char				*pf_luitoa_base(unsigned long n, char *base);
int					pf_applyflags_nb(char **str, t_flags *flags);
int					pf_applyflags_str(char **str, t_flags *flags);
int					pf_applyflags_x(char **str, t_flags *flags);
int					pf_applyflags_o(char **str, t_flags *flags);
char				*pf_unicode(unsigned int i);

#endif
