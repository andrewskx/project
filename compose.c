/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 19:37:57 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/06 19:41:18 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	compose(t_require *tool)
{
	if (tool->spec == 'i' || tool->spec == 'I' || tool->spec == 'd' || tool->spec == 'D')
	{
		if (tool->str[0] == '-')
		{
			if (tool->sign == -1)
			{
				ft_putchar('-');
				ft_putnchar(tool->precision - (int)ft_strlen(tool->str + 1), '0');
				ft_putstr(tool->str + 1);
				if (tool->precision > (int)ft_strlen(tool->str))
					ft_putnchar(tool->width - tool->precision, ' ');
			}
			else
			{
				ft_putnchar(tool->width - (int)ft_strlen(tool->str + 1) - tool->precision, ' ');
				ft_putchar('-');
				ft_putnchar(tool->precision - (int)ft_strlen(tool->str + 1), '0');
				ft_putstr(tool->str + 1);
			}
		}
	}
}
