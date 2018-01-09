/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 19:37:57 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/09 21:21:07 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_s(t_require *tool)
{
	if (tool->spec == 's')
	{
		if (tool->precision > (int)ft_strlen(tool->str) && tool->sign < 0)
		{
			ft_putstr(tool->str);
			ft_putnchar(tool->width - (int)ft_strlen(tool->str), ' ', 0);
		}
		else if (tool->precision < (int)ft_strlen(tool->str) && tool->sign >= 0)
		{
			ft_putnchar(tool->width - tool->precision, ' ', 0);
			ft_putnchar(tool->precision, 0, tool->str);
		}
		else if (tool->precision > (int)ft_strlen(tool->str) && tool->sign >= 0)
		{
			ft_putnchar(tool->width - (int)ft_strlen(tool->str), ' ', 0);
			ft_putstr(tool->str);
		}
		else if (tool->precision < (int)ft_strlen(tool->str) && tool->sign < 0)
		{
			ft_putnchar(tool->width - tool->precision, ' ', 0);
			ft_putnchar(tool->precision, 0, tool->str);
		}
	}
}

void	conversion_ss(t_require *tool)
{
	if (tool->spec == 'S')
	{
		ft_putwstr((wchar_t const *)tool->wstr);
	}
}

void	conversion_cc(t_require *tool)
{
	if (tool->spec == 'c')
	{
		if (tool->sign < 0)
		{
			ft_putstr(tool->str);
			ft_putnchar(tool->width - 1, ' ', 0);
		}
		else
		{
			ft_putnchar(tool->width - 1, ' ', 0);
			ft_putstr(tool->str);
		}
	}
	if (tool->spec == 'C')
	{
		if (tool->sign < 0)
		{
			ft_putwstr(tool->wstr);
			ft_putnchar(tool->width - 1, ' ', 0);
		}
		else
		{
			ft_putnchar(tool->width - 1, ' ', 0);
			ft_putwstr(tool->wstr);
		}
	}
}

void	conversion_uu(t_require *tool)
{
	if (tool->sign < 0 && tool->dot)
	{
		ft_putstr(tool->str);
		ft_putnchar(tool->width - (int)ft_strlen(tool->str), ' ', 0);
	}
	else if (tool->sign >= 0 && tool->dot)
	{
		ft_putnchar(tool->width - (int)ft_strlen(tool->str), ' ', 0);
		ft_putstr(tool->str);
	}
	else if (tool->sign < 0 && !tool->dot)
	{
		ft_putstr(tool->str);
		ft_putnchar(tool->width - (int)ft_strlen(tool->str), ' ', 0);
	}
	else if (tool->sign >= 0 && !tool->dot)
	{
		if (tool->zero)
			ft_putnchar(tool->width - (int)ft_strlen(tool->str), '0', 0);
		else
			ft_putnchar(tool->width - (int)ft_strlen(tool->str), ' ', 0);
		ft_putstr(tool->str);
	}
}
