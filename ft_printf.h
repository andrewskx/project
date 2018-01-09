/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:36:24 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/09 20:57:15 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
#define SPECIFIERS "sSpdDioOuUxXcC%"
typedef    struct  s_require
{
    int64_t aux1;
    uint64_t aux;
    va_list ptr;
    int index;
    int symbols;
    int alt;
    int zero;
    int pad;
    int sign;
	int dot;
    int width;
    int precision;
    char len;
    char spec;
    char *str;
	wchar_t *wstr;
}               t_require;
void zero_fill(t_require *tool);
char 	*ft_capitalize(char *str);
char *ft_strnew_char(uint32_t, char c);
char    *char2str(char c);
wchar_t *wchar2str(wchar_t c);
void	func2conv(t_require *tool);
void	conversion_xx_prefix(t_require *tool);
void	conversion_xx(t_require *tool);
void	conversion_p(t_require *tool);
void	conversion_s(t_require *tool);
void	conversion_ss(t_require *tool);
void	conversion_oo(t_require *tool);
void    conversion_uu(t_require *tool);
void	conversion_cc(t_require *tool);
void    print_result(t_require *tool);
void    clean_tool(t_require *tool);
void    conv_manage(t_require *tool, const char *format);
void    length_manage(t_require *tool, const char *format);
void    precis_manage(t_require *tool, const char *format);
void    min_width(t_require *tool, const char *format);
void    flag_manage(t_require *tool, const char *format);
int     is_spec(char x);
void    print_while(t_require *tool, const char *format);
int     ft_printf(const char *format, ...);
char    *ft_hex(uint64_t  num, char x);
char    *ft_oct(uint64_t num);
void    print_format(t_require *tool);
void    print_format2(t_require *tool);
void    print_format3(t_require *tool);
#endif
