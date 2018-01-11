/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 19:37:57 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/11 17:59:53 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	terminate_s(t_require *tool)
{
	int i;

	i = 0;
	if (tool->precision < ft_strlen(tool->str) &&
		tool->dot && tool->str)
	{
		while (i < tool->precision)
			i++;
		tool->str[i] = '\0';
	}
}

void	conversion_s(t_require *tool)
{
	terminate_s(tool);
	if (tool->width < (int)ft_strlen(tool->str) && tool->sign < 0)
	{
		ft_putnchar_m((int)ft_strlen(tool->str), 0, tool->str,tool);
		ft_putnchar_m(tool->width - tool->precision, ' ', 0,tool);
	}
	else if (tool->width < (int)ft_strlen(tool->str) && tool->sign >= 0 && tool->dot)
	{
		ft_putnchar_m(tool->width - (int)ft_strlen(tool->str), ' ', 0, tool);
		ft_putnchar_m((int)ft_strlen(tool->str), 0, tool->str, tool);
	}
	else if (tool->width > (int)ft_strlen(tool->str) && tool->sign < 0)
	{
		ft_putnchar_m((int)ft_strlen(tool->str), 0, tool->str, tool);
		ft_putnchar_m(tool->width - (int)ft_strlen(tool->str), ' ', 0, tool);
	}
	else if (tool->width > (int)ft_strlen(tool->str) && tool->sign >= 0)
	{
		ft_putnchar_m(tool->width - (int)ft_strlen(tool->str), ' ', 0, tool);
		ft_putnchar_m((int)ft_strlen(tool->str), 0, tool->str, tool);
	}
	else
		ft_putnchar_m((int)ft_strlen(tool->str), 0, tool->str, tool);
}

void	conversion_ss(t_require *tool)
{
	if (tool->spec == 'S')
	{
		ft_putwstr_m((wchar_t const *)tool->wstr, tool);
	}
}

void	conversion_cc(t_require *tool)
{
	if (tool->spec == 'c')
	{
		if (tool->sign < 0)
		{
			ft_putnchar_m((int)ft_strlen(tool->str), 0, tool->str, tool);
			ft_putnchar_m(tool->width - 1, ' ', 0, tool);
		}
		else
		{
			ft_putnchar_m(tool->width - 1, ' ', 0, tool);
			ft_putnchar_m((int)ft_strlen(tool->str), 0, tool->str, tool);
		}
	}
	if (tool->spec == 'C')
	{
		if (tool->sign < 0)
		{
			ft_putwstr_m(tool->wstr, tool);
			ft_putnchar_m(tool->width - 1, ' ', 0, tool);
		}
		else
		{
			ft_putnchar_m(tool->width - 1, ' ', 0, tool);
			ft_putwstr_m(tool->wstr, tool);
		}
	}
}

void	conversion_uu(t_require *tool)
{
	if (tool->sign < 0 && tool->dot)
	{
		ft_putnchar_m((int)ft_strlen(tool->str), 0, tool->str, tool);
		ft_putnchar_m(tool->width - (int)ft_strlen(tool->str), ' ', 0, tool);
	}
	else if (tool->sign >= 0 && tool->dot)
	{
		ft_putnchar_m(tool->width - (int)ft_strlen(tool->str), ' ', 0, tool);
		ft_putnchar_m((int)ft_strlen(tool->str), 0, tool->str, tool);
	}
	else if (tool->sign < 0 && !tool->dot)
	{
		ft_putnchar_m((int)ft_strlen(tool->str), 0, tool->str, tool);
		ft_putnchar_m(tool->width - (int)ft_strlen(tool->str), ' ', 0, tool);
	}
	else if (tool->sign >= 0 && !tool->dot)
	{
		if (tool->zero)
			ft_putnchar_m(tool->width - (int)ft_strlen(tool->str), '0', 0, tool);
		else
			ft_putnchar_m(tool->width - (int)ft_strlen(tool->str), ' ', 0, tool);
		ft_putnchar_m((int)ft_strlen(tool->str), 0, tool->str, tool);
	}
}
