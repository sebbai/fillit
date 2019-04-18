/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:59:56 by sebbaill          #+#    #+#             */
/*   Updated: 2019/01/17 16:07:05 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_del_back(t_list **lst)
{
	t_list	*temp;
	t_list	*before;

	if (!lst)
		return (*lst);
	if ((*lst)->next == NULL)
	{
		free(lst);
		lst = NULL;
		return (*lst);
	}
	temp = *lst;
	before = *lst;
	while (temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}
	before->next = NULL;
	free(temp);
	temp = NULL;
	return (*lst);
}
