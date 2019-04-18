/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:32:06 by sebbaill          #+#    #+#             */
/*   Updated: 2019/01/10 17:32:08 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list **list)
{
	t_list	*next;

	while (list)
	{
		next = (*list)->next;
		ft_putstr((*list)->content);
		ft_putchar('\n');
		ft_putnbr((*list)->content_size);
		*list = next;
	}
}
