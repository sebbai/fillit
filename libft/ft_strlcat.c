/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:20:22 by sebbaill          #+#    #+#             */
/*   Updated: 2019/01/03 21:34:44 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	if (size == 0)
		return (ft_strlen((char*)src));
	while ((dest[j]) && (j < size))
		j++;
	i = j;
	while ((src[i - j]) && (i < size - 1))
	{
		dest[i] = src[i - j];
		i++;
	}
	if (j < size)
		dest[i] = '\0';
	if (j > size)
		return (size + ft_strlen((char*)src));
	return (j + ft_strlen((char*)src));
}
