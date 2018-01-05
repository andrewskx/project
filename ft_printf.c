/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:21:22 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/05 20:43:17 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *char2str(char c)
{
    char *ptr;

    ptr = (char*)malloc(sizeof(char) * 2);
    ptr[1] = '\0';
    ptr[0] = c;
    return (ptr);
}

int     ft_printf(const char *format, ...)
{
    t_require tool;

    tool.symbols = 0;
    tool.str = 0;
    clean_tool(&tool);
    va_start(tool.ptr, format);
    print_while(&tool, format);



    return (tool.symbols);   
}

void     print_while(t_require *tool, const char *format)
{
    tool->index = 0;
    while (format[tool->index] != '\0')
    {
        while (format[tool->index] != '%' && format[tool->index] != '\0')
        {
            write(1, &format[tool->index], 1);
            tool->index++;
            tool->symbols++;
        }
        tool->index++;
        flag_manage(tool, format);
        min_width(tool, format);
        precis_manage(tool, format);
        length_manage(tool, format);
        conv_manage(tool, format);
        print_format(tool, format);
        clean_tool(tool);
    }
}

int     is_spec(char x)
{
    //printf("\nis_spec");
    int i;

    i = 0;
    while (i < 15)
    {
        if (SPECIFIERS[i] == x)
            return (1);
        i++;
    }
    return (0);
}

void    flag_manage(t_require *tool, const char *format)
{
    //printf("\nflag_manage index = %i", *index);
    while ((format[tool->index] == '#' || format[tool->index] == '-' || format[tool->index] == '+'||
                format[tool->index] == ' ' || format[tool->index] == '0') && format[tool->index]) 
    {
        if (format[tool->index] == '#')
            tool->alt = 1;
        if (format[tool->index] == '-')
            tool->sign = -1;
        if (format[tool->index] == '+')
            tool->sign = 1;
        if (format[tool->index] == ' ')
            tool->pad = 1;
        if (format[tool->index] == '0')
            tool->zero = 1;
        tool->index++;
    }
}

void    min_width(t_require *tool, const char *format)
{
    if (format[tool->index] == '*')
    {
        tool->width = va_arg(tool->ptr, int);
        tool->index++;
    }
    if (format[tool->index] >= '0' && format[tool->index] <= '9')
    {
        tool->width = ft_atoi((const char*)(format + tool->index));
        while (format[tool->index] >= '0' && format[tool->index] <= '9' && format[tool->index])
            tool->index++;
        if (format[tool->index] == '*')
            tool->width = va_arg(tool->ptr, int);
        tool->index++;
    }
}

void    precis_manage(t_require *tool, const char *format)
{
    //printf("\nprecision_manage");
    if (format[tool->index] == '.')
    {
        tool->index++;
        if (format[tool->index] == '*')
        {
            tool->precision = va_arg(tool->ptr, int);
            tool->index++;
        }
        if (format[tool->index] >= '0' && format[tool->index] <= '9')
        {
            tool->precision = ft_atoi((const char*)(&format[tool->index]));
            while (format[tool->index] >= '0' && format[tool->index] <= '9' && format[tool->index])
                tool->index++;
        }
    }
}

void    length_manage(t_require *tool, const char *format)
{
    // printf("\nlenght_manage");
    if (format[tool->index] == 'h')
    {
        if (format[tool->index + 1] == 'h')
            tool->len = 'H';
        else
            tool->len = 'h';
    }
    if (format[tool->index] == 'l')
    {
        if (format[tool->index + 1] == 'l')
            tool->len = 'L';
        else
            tool->len = 'l';
    }
    if (format[tool->index] == 'j')
        tool->len = 'j';
    if (format[tool->index] == 'z')
        tool->len = 'z';
    if (tool->len >= 'a' && tool->len <= 'z' && tool->len != 0)
        tool->index++;
    if (tool->len >= 'A' && tool->len <= 'Z' && tool->len != 0)
        tool->index += 2;
}

void    conv_manage(t_require *tool, const char *format)
{
    //printf("\nconv_manage");
    while (!is_spec(format[tool->index]) && format[tool->index])
        tool->index++;
    if (format[tool->index])
    {
        tool->spec = format[tool->index];
        tool->index++;
    }
}

void    print_format(t_require *tool, const char *format)
{
    int64_t aux1;
    uint64_t aux;
    char *ptr;

    ptr = 0;
    if (tool->spec == 'd' || tool->spec == 'D' || tool->spec == 'i' || tool->spec == 'I')
    {
        if (tool->len == 'h')
            aux1 = (short int)va_arg(tool->ptr, int32_t);
        else if (tool->len == 'H')
            aux1 = (char)va_arg(tool->ptr, int32_t);
        else if (tool->len == 'l')
            aux1 = (int64_t)va_arg(tool->ptr, int64_t);
        else if (tool->len == 'L')
            aux1 = (int64_t)va_arg(tool->ptr, int64_t);
        else if (tool->len == 'z')
            aux1 = (int64_t)va_arg(tool->ptr, int64_t);
        else if (tool->len == 'j')
            aux1 = (int64_t)va_arg(tool->ptr, int64_t);
        else
            aux1 = (int32_t)va_arg(tool->ptr, int32_t);
        tool->str = ft_itoa64(aux1);
    }
    else if (tool->spec == 'u' || tool->spec == 'U' || tool->spec == 'o' || tool->spec == 'O'
            || tool->spec == 'x' || tool->spec == 'X')
    {
        if (tool->len == 'h')
            aux = (unsigned short int)va_arg(tool->ptr, uint32_t);
        else if (tool->len == 'H')
            aux = (unsigned char)va_arg(tool->ptr, uint32_t);
        else if (tool->len == 'l')
            aux = (unsigned long int)va_arg(tool->ptr, uint64_t);
        else if (tool->len == 'L')
            aux = (uint64_t)va_arg(tool->ptr, uint64_t);
        else if (tool->len == 'z')
            aux = (uint64_t)va_arg(tool->ptr, uint64_t);
        else if (tool->len == 'j')
            aux = (uint64_t)va_arg(tool->ptr, uint64_t);
        else
            aux = (uint32_t)va_arg(tool->ptr, uint32_t);
        if (tool->spec == 'u' || tool->spec == 'U')
            tool->str = ft_uitoa((uint64_t)aux);
        else if (tool->spec == 'o' || tool->spec == 'O')
            tool->str = ft_oct(aux);
        else if (tool->spec == 'x' || tool->spec == 'X')
            tool->str = ft_hex(aux, tool->spec);
    }
    else if (tool->spec == 's')
        tool->str = ft_strdup(va_arg(tool->ptr, char *));
    else if (tool->spec == 'c')
        tool->str = (char*)char2str(va_arg(tool->ptr, int32_t));
    if (tool->spec != 0)
         ft_putstr(tool->str);
    if (tool->str)
        free(tool->str);
}

void    clean_tool(t_require *tool)
{
    tool->alt = 0;
    tool->zero = 0;
    tool->pad = 0;
    tool->sign = 0;
    tool->width = 0;
    tool->precision = 0;
    tool->len = 0;
    tool->spec = 0;
}

void    print_result(t_require *tool, const char *format)
{
    printf("\nCheck : \nsymbols = %i\nalt = %i\nzero = %i\npad = %i\nsign = %i\nwidth = %i\nprecision = %i\nlen = %c\nspec = %c\n",tool->symbols, tool->alt, tool->zero, tool->pad, tool->sign, tool->width, tool->precision, tool->len, tool->spec);
    clean_tool(tool);
}

int main(void)
{
    ft_printf("%ju aaaa  lala - a %s,123, %c,%s",-1234567890, "avc", 'c', "pshol");
    return (0);
}
