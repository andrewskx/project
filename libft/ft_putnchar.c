/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:36:22 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/11 17:34:47 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnchar(int n, char c, char *str)
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
}
