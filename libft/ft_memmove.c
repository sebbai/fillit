/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:04:54 by sebbaill          #+#    #+#             */
/*   Updated: 2018/12/18 18:54:42 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp_dest;
	char	*temp_src;

	temp_dest = (char*)dest;
	temp_src = (char*)src;
	if (temp_src < temp_dest)
	{
		while ((int)(--n) >= 0)
			temp_dest[n] = temp_src[n];
		return (temp_dest);
	}
	return (ft_memcpy(temp_dest, temp_src, n));
}
