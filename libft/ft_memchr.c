/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:04:54 by sebbaill          #+#    #+#             */
/*   Updated: 2018/11/20 16:22:29 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	unsigned char *copy_str;

	copy_str = (unsigned char*)str;
	while (size-- > 0)
		if (*(copy_str++) == (unsigned char)c)
			return (copy_str - 1);
	return (0);
}
