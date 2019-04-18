/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:25:15 by sebbaill          #+#    #+#             */
/*   Updated: 2019/01/23 16:25:16 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (temp->next == NULL)
		new->next = NULL;
	else
		new->next = temp;
}
