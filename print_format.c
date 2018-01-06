/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 19:19:57 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/06 19:37:00 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(t_require *tool)
{
	if (tool->spec == 'd' || tool->spec == 'D' ||
		tool->spec == 'i' || tool->spec == 'I')
	{
		if (tool->len == 'h')
			tool->aux1 = (short int)va_arg(tool->ptr, int32_t);
		else if (tool->len == 'H')
			tool->aux1 = (char)va_arg(tool->ptr, int32_t);
		else if (tool->len == 'l')
			tool->aux1 = (int64_t)va_arg(tool->ptr, int64_t);
		else if (tool->len == 'L')
			tool->aux1 = (int64_t)va_arg(tool->ptr, int64_t);
		else if (tool->len == 'z')
			tool->aux1 = (int64_t)va_arg(tool->ptr, int64_t);
		else if (tool->len == 'j')
			tool->aux1 = (int64_t)va_arg(tool->ptr, int64_t);
		else
			tool->aux1 = (int32_t)va_arg(tool->ptr, int32_t);
		tool->str = ft_itoa64(tool->aux1);
	}
	else
		print_format2(tool);
}

void	print_format2(t_require *tool)
{
	if (tool->spec == 'u' || tool->spec == 'U' ||
			tool->spec == 'o' || tool->spec == 'O'
			|| tool->spec == 'x' || tool->spec == 'X')
	{
		if (tool->len == 'h')
			tool->aux = (unsigned short int)va_arg(tool->ptr, uint32_t);
		else if (tool->len == 'H')
			tool->aux = (unsigned char)va_arg(tool->ptr, uint32_t);
		else if (tool->len == 'l')
			tool->aux = (unsigned long int)va_arg(tool->ptr, uint64_t);
		else if (tool->len == 'L' || tool->len == 'z' || tool->len == 'j')
			tool->aux = (uint64_t)va_arg(tool->ptr, uint64_t);
		else
			tool->aux = (uint32_t)va_arg(tool->ptr, uint32_t);
		if (tool->spec == 'u' || tool->spec == 'U')
			tool->str = ft_uitoa((uint64_t)tool->aux);
		else if (tool->spec == 'o' || tool->spec == 'O')
			tool->str = ft_oct(tool->aux);
		else if (tool->spec == 'x' || tool->spec == 'X')
			tool->str = ft_hex(tool->aux, tool->spec);
	}
	else
		print_format3(tool);
}

void	print_format3(t_require *tool)
{
	if (tool->spec == 's')
		tool->str = ft_strdup(va_arg(tool->ptr, char *));
	else if (tool->spec == 'c')
		tool->str = (char*)char2str(va_arg(tool->ptr, int32_t));
	else if (tool->spec == 'p')
		tool->str = (char*)(ft_hex(va_arg(tool->ptr, uint64_t), 'x'));
	else if (tool->spec == 'S')
		tool->wstr = va_arg(tool->ptr, wchar_t*);
	else if (tool->spec == 'C')
		tool->wstr = wchar2str(va_arg(tool->ptr, wchar_t));
	else if (tool->spec == '%')
		tool->str = char2str('%');
}
