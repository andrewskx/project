/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:31:28 by anboscan          #+#    #+#             */
/*   Updated: 2018/01/09 16:58:55 by anboscan         ###   ########.fr       */
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
