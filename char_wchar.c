/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:31:28 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/11 17:46:22 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*wchar2str(wchar_t c)
{
	wchar_t *ptr;

	ptr = (wchar_t*)malloc(sizeof(wchar_t) * 2);
	ptr[1] = '\0';
	ptr[0] = c;
	return (ptr);
}

char	*char2str(char c)
{
	char *ptr;

	ptr = (char*)malloc(sizeof(char) * 2);
	ptr[1] = '\0';
	ptr[0] = c;
	return (ptr);
}

void	ft_putnchar_m(int n, char c, char *str, t_require *tool)
{
	int i;

	i = 0;
	if (!str)
		while (i < n)
		{
			write(1, &c, 1);
			i++;
		}
	else if (str)
	{
		while (i < n && str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	tool->symbols += i;
}

void	ft_putwchar_m(wchar_t chr, t_require *tool)
{
	if (chr <= 0x7F)
		ft_putnchar_m(1, chr, 0, tool);
	else if (chr <= 0x7FF)
	{
		ft_putnchar_m(1, (chr >> 6) + 0xC0, 0, tool);
		ft_putnchar_m(1, (chr & 0x3F) + 0x80, 0, tool);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putnchar_m(1, (chr >> 12) + 0xE0, 0, tool);
		ft_putnchar_m(1, ((chr >> 6) & 0x3F) + 0x80, 0, tool);
		ft_putnchar_m(1, (chr & 0x3F) + 0x80, 0, tool);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putnchar_m(1, (chr >> 18) + 0xF0, 0, tool);
		ft_putnchar_m(1, ((chr >> 12) & 0x3F) + 0x80, 0, tool);
		ft_putnchar_m(1, ((chr >> 6) & 0x3F) + 0x80, 0, tool);
		ft_putnchar_m(1, (chr & 0x3F) + 0x80, 0, tool);
	}
}

void	ft_putwstr_m(wchar_t const *str, t_require *tool)
{
	while (*str)
		ft_putwchar_m(*str++, tool);
}
