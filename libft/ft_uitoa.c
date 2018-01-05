/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:39:22 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/05 16:42:10 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_uitoa(uint64_t n)
{
    uint64_t		tmpn;
    int      		len;
    char	*str;

    tmpn = n;
    len = 2;
    while (tmpn /= 10)
        len++;
    if ((str = (char*)malloc(sizeof(char) * len)) == 0)
        return (0);
    str[--len] = '\0';
    while (len--)
    {
        str[len] = n % 10 + '0';
        n = n / 10;
    }
    return (str);
}
