/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:00:31 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/06 19:12:48 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_itoa_isnegative(int64_t *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

static char	*ft_check(int64_t n)
{
	char *ptr;

	if (n == 9223372036854775807)
	{
		ptr = ft_strdup("9223372036854775807");
		return (ptr);
	}
	if (n == (-9223372036854775807 - 1))
	{
		ptr = ft_strdup("-9223372036854775808");
		return (ptr);
	}
	return (0);
}

static void	ft_neg(int *neg, char *s)
{
	if (*neg)
		s[0] = '-';
}

char		*ft_itoa64(int64_t n)
{
	int64_t		tmpn;
	int64_t		len;
	int			negative;
	char		*str;

	if ((str = ft_check(n)) == 0)
	{
		tmpn = n;
		len = 2;
		negative = 0;
		ft_itoa_isnegative(&n, &negative);
		while (tmpn /= 10)
			len++;
		len += negative;
		if ((str = (char*)malloc(sizeof(char) * len)) == 0)
			return (0);
		str[--len] = '\0';
		while (len--)
		{
			str[len] = n % 10 + '0';
			n = n / 10;
		}
		ft_neg(&negative, str);
	}
	return (str);
}
