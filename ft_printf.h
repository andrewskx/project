/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:36:24 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/05 20:43:20 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
#define SPECIFIERS "sSpdDioOuUxXcC%"
typedef     struct  s_types
{
    short int t_short;
    unsigned short int t_ushort;
    char    t_char;
    unsigned char t_uchar;
    long int    t_longint;
    unsigned long int t_ulongint;
    long long int   t_longlong;
    unsigned long long int t_ulonglong;
}                   t_types;
typedef    struct  s_require
{
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
    t_types type;
}                   t_require;
void    print_result(t_require *tool, const char *format);
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
void    print_format(t_require *tool, const char *format);
#endif
