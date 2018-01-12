/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_manage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:46:32 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/11 17:17:23 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	join_and_free(char *str, t_require *tool)
{
	char *aux;

	aux = ft_strjoin(str, tool->str);
	if (tool->str)
		free(tool->str);
	tool->str = aux;
}

void	precision_dd(t_require *tool)
{
	char *aux;

	if (!tool->precision && tool->dot && tool->str[0] == '0')
		tool->str[0] = '\0';
	else if ((tool->width > (int)ft_strlen(tool->str) -1) &&
			(tool->plus || tool->is_neg || tool->pad) && tool->zero)
	{
		aux = ft_strnew_char(tool->width - (int)ft_strlen(tool->str) - 1, '0');
		join_and_free(aux, tool);
		free(aux);
	}else if (tool->alt && !tool->precision && !tool->dot
		&& ft_strlen(tool->str) == 1 && tool->str[0] == '0')
		tool->str[0] = '\0';
}

void	check_neg(t_require *tool)
{
	char *str;

	if (tool->str)
	if (tool->str[0] == '-')
	{
		tool->is_neg = 1;
		str = ft_strdup(&tool->str[1]);
		if (tool->str)
			free(tool->str);
		tool->str = str;
	}
}

void	conversion_dd(t_require *tool)
{
	check_neg(tool);
	zero_fill(tool);
	precision_dd(tool);
	if (tool->pad && !tool->plus && !tool->is_neg)
		join_and_free(" ", tool);
	else if (tool->plus && !tool->is_neg && !tool->zero)
		join_and_free("+", tool);
	else if (tool->plus && !tool->is_neg && tool->zero)
		join_and_free("+", tool);
	else if (tool->is_neg && !tool->zero)
		join_and_free("-", tool);
	else if (tool->is_neg && tool->zero)
		join_and_free("-", tool);
	conversion_uu(tool);
}



void	conversion_xx_prefix(t_require *tool)
{
	if ((tool->spec == 'X' || tool->spec == 'x') &&
		tool->alt && !tool->dot && ft_strlen(tool->str) > 0)
	{
		join_and_free("0x", tool);
		if (tool->spec == 'X')
			ft_capitalize(tool->str);
	}
	else if (!ft_strlen(tool->str) && tool->alt && !tool->dot)
		join_and_free("0", tool);
}


void	conversion_xx(t_require *tool)
{
	char *aux;
	char *aux2;

	precision_dd(tool);
	if (tool->sign >= 0 && tool->zero && !tool->dot &&
		(tool->width > (int)ft_strlen(tool->str) + 2))
	{
		aux = ft_strnew_char(tool->width - (int)ft_strlen(tool->str) - 2, '0');
		aux2 = ft_strjoin(aux, tool->str);
		free(aux);
		free(tool->str);
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
	char *aux2;
	char *aux;

	if (tool->zero && !tool->dot && (tool->width > tool->precision + 2))
	{
		aux = ft_strnew_char(tool->width - (int)ft_strlen(tool->str) - 2, '0');
		aux2 = ft_strjoin(aux, tool->str);
		free(aux);
		free(tool->str);
		tool->str = aux2;
	}
	zero_fill(tool);
	join_and_free("0x", tool);
	conversion_uu(tool);
}

void	conversion_oo(t_require *tool)
{
	precision_dd(tool);
	if (tool->alt && (tool->precision <= (int)ft_strlen(tool->str)))
	{
		join_and_free("0", tool);
		conversion_uu(tool);
	}
	else if ((tool->precision > (int)ft_strlen(tool->str)))
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
		join_and_free(zero, tool);
	}
	else if ((tool->spec == 'o' || tool->spec == 'O') 
		&& tool->alt && !(int)ft_strlen(tool->str))
		join_and_free("0", tool);
	else if (tool->is_neg && tool->zero &&
		tool->width > (int)ft_strlen(tool->str) + 1)
	{
		n = tool->width - (int)ft_strlen(tool->str) - 1;
		aux = ft_strnew_char(n, '0');
		join_and_free(aux, tool);
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
	else if (tool->spec == 'd' || tool->spec == 'i' || tool->spec == 'D')
		conversion_dd(tool);
	else if (tool->spec == '%')
		conversion_uu(tool);
}
