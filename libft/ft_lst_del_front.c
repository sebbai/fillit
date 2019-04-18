/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:23:45 by sebbaill          #+#    #+#             */
/*   Updated: 2019/01/17 16:16:54 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_del_front(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return (*lst);
	temp = (*lst)->next;
	free(*lst);
	*lst = NULL;
	return (temp);
}
