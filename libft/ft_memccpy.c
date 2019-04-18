/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:30:41 by sebbaill          #+#    #+#             */
/*   Updated: 2018/12/12 15:30:46 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*temp_dest;
	const unsigned char	*temp_src;
	unsigned int		i;

	i = 0;
	temp_dest = dest;
	temp_src = src;
	while (i < n)
	{
		temp_dest[i] = (unsigned char)temp_src[i];
		if (temp_src[i] == (unsigned char)c)
			return (temp_dest + i + 1);
		i++;
	}
	return (NULL);
}
