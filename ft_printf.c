/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:21:22 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/09 17:00:36 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_require tool;

	tool.symbols = 0;
	tool.str = 0;
	clean_tool(&tool);
	va_start(tool.ptr, format);
	print_while(&tool, format);
	va_end(tool.ptr);
	return (tool.symbols);
}

void	print_while(t_require *tool, const char *format)
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
		if (!format[tool->index])
			break;
		tool->index++;
		flag_manage(tool, format);
		min_width(tool, format);
		precis_manage(tool, format);
		length_manage(tool, format);
		conv_manage(tool, format);
		print_format(tool);
		func2conv(tool);
		clean_tool(tool);
	}
}

int		is_spec(char x)
{
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

void	clean_tool(t_require *tool)
{
	tool->alt = 0;
	tool->zero = 0;
	tool->pad = 0;
	tool->sign = 0;
	tool->width = 0;
	tool->precision = 0;
	tool->len = 0;
	tool->spec = 0;
	tool->dot = 0;
}
