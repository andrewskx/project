/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:36:24 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/06 19:38:12 by anboscan         ###   ########.fr       */
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
    int width;
    int precision;
    char len;
    char spec;
    char *str;
	wchar_t *wstr;
}               t_require;
char    *char2str(char c);
wchar_t *wchar2str(wchar_t c);
void    compose(t_require *tool);
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
