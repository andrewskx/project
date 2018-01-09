/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_manage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:46:32 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/09 21:20:36 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_xx_prefix(t_require *tool)
{
	char *aux;

	if (tool->spec == 'X' && tool->alt)
	{
		aux = ft_strjoin("0X", tool->str);
		if (tool->str)
			free(tool->str);
		tool->str = aux;
		ft_capitalize(tool->str);
	}
	else if (tool->spec == 'x' && tool->alt)
	{
		aux = ft_strjoin("0x", tool->str);
		if (tool->str)
			free(tool->str);
		tool->str = aux;
	}
}


void	conversion_xx(t_require *tool)
{
	char *aux;
	char *aux2;

	if (tool->zero && !tool->dot && (tool->width > (int)ft_strlen(tool->str)))
	{
		aux = ft_strnew_char(tool->width - (int)ft_strlen(tool->str), '0');
		aux2 = ft_strjoin(aux, tool->str);
		free(aux);
		free(aux2);
		tool->str = aux2;
		conversion_xx_prefix(tool);
		conversion_uu(tool);
	}
	else
	{
		zero_fill(tool);
		conversion_xx_prefix(tool);
		conversion_uu(tool);
	}
}

void	conversion_p(t_require *tool)
{
	char *aux;
	char *aux2;

	if (tool->zero && !tool->dot && (tool->width > tool->precision + 2))
	{
		aux = ft_strnew_char(tool->width - (int)ft_strlen(tool->str) - 2, '0');
		aux2 = ft_strjoin(aux, tool->str);
		free(aux);
		free(tool->str);
		tool->str = aux2;
	}
	zero_fill(tool);
	aux = ft_strjoin("0x", tool->str);
	if (tool->str)
		free(tool->str);
	tool->str = aux;
	conversion_uu(tool);
}

void	conversion_oo(t_require *tool)
{
	char *aux;

	if (tool->alt && (tool->precision < (int)ft_strlen(tool->str)))
	{
		aux = ft_strjoin("0", tool->str);
		if (tool->str)
			free(tool->str);
		tool->str = aux;
		conversion_uu(tool);
	}
	else if (tool->alt && (tool->precision > (int)ft_strlen(tool->str)))
	{
		zero_fill(tool);
		conversion_uu(tool);
	}
	else if (tool->alt == 0)
	{
		zero_fill(tool);
		conversion_uu(tool);
	}
}

char	*ft_strnew_char(uint32_t n, char c)
{
	char		*ptr;
	uint32_t	i;

	i = 0;
	ptr = (char*)malloc(sizeof(char) * (n + 1));
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	zero_fill(t_require *tool)
{
	char	*zero;
	char	*aux;
	int		n;

	aux = 0;
	zero = 0;
	if (tool->precision > (int)ft_strlen(tool->str))
	{
		n = tool->precision - (int)ft_strlen(tool->str);
		zero = ft_strnew_char(n, '0');
		aux = ft_strjoin(zero, tool->str);
		if (tool->str)
			free(tool->str);
		tool->str = aux;
		if (zero)
			free(zero);
	}
}

void	func2conv(t_require *tool)
{
	if (tool->spec == 'u' || tool->spec == 'U')
	{
		zero_fill(tool);
		conversion_uu(tool);
	}
	if (tool->spec == 'o' || tool->spec == 'O')
		conversion_oo(tool);
	else if (tool->spec == 's')
		conversion_s(tool);
	else if (tool->spec == 'S')
		conversion_ss(tool);
	else if (tool->spec == 'c' || tool->spec == 'C')
		conversion_cc(tool);
	else if (tool->spec == 'p')
		conversion_p(tool);
	else if (tool->spec == 'x' || tool->spec == 'X')
		conversion_xx(tool);
}
