/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:04:54 by sebbaill          #+#    #+#             */
/*   Updated: 2018/11/20 16:22:29 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t size)
{
	const unsigned char *memory1;
	const unsigned char *memory2;

	memory1 = s1;
	memory2 = s2;
	while (size-- > 0)
		if (*memory1++ != *memory2++)
			return (*(memory1 - 1) - *(memory2 - 1));
	return (0);
}
