/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision_len_conv.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 19:03:27 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/11 18:13:48 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_manage(t_require *tool, const char *format)
{
	while ((format[tool->index] == '#' || format[tool->index] == '-' ||
			format[tool->index] == '+' ||
			format[tool->index] == ' ' || format[tool->index] == '0') && format[tool->index])
	{
		if (format[tool->index] == '#')
			tool->alt = 1;
		if (format[tool->index] == '-')
			tool->sign = -1;
		if (format[tool->index] == '+')
			tool->plus = 1;
		if (format[tool->index] == ' ')
			tool->pad = 1;
		if (format[tool->index] == '0')
			tool->zero = 1;
		tool->index++;
	}
}

void	min_width(t_require *tool, const char *format)
{
	if (format[tool->index] == '*')
	{
		tool->width = va_arg(tool->ptr, int);
		tool->index++;
	}
	if (format[tool->index] >= '0' && format[tool->index] <= '9')
	{
		tool->width = ft_atoi((const char*)(format + tool->index));
		while (format[tool->index] >= '0' &&
				format[tool->index] <= '9' && format[tool->index])
			tool->index++;
		if (format[tool->index] == '*')
		{
			tool->width = va_arg(tool->ptr, int);
			tool->index++;
		}
	}
}

void	precis_manage(t_require *tool, const char *format)
{
	if (format[tool->index] == '.')
	{
		tool->dot = 1;
		tool->index++;
		if (format[tool->index] == '*')
		{
			tool->precision = va_arg(tool->ptr, int);
			tool->index++;
		}
		if (format[tool->index] >= '0' && format[tool->index] <= '9')
		{
			tool->precision = ft_atoi((const char*)(&format[tool->index]));
			while (format[tool->index] >= '0' &&
				format[tool->index] <= '9' && format[tool->index])
				tool->index++;
		}
		else
		{
			flag_manage(tool, format);
			min_width(tool, format);
			precis_manage(tool, format);
		}
	}
}

void	length_manage(t_require *tool, const char *format)
{
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

void	conv_manage(t_require *tool, const char *format)
{
	while (!is_spec(format[tool->index]) && format[tool->index])
		length_manage(tool, format);
	if (format[tool->index])
	{
		tool->spec = format[tool->index];
		tool->index++;
	}
}
