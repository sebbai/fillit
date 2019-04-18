/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynaamane <ynaamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:59:57 by ynaamane          #+#    #+#             */
/*   Updated: 2019/04/17 17:06:17 by ynaamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

/*
** Can be use for freeing a list made with read_tetri
*/

t_list		*free_list(t_list *list)
{
	t_etris		*tetris;
	t_list		*next;

	while(list)
	{
		tetris = (t_etris *)list->content;
		next = list->next;
		free_tetris(tetris);
		ft_memdel((void **)&list);
		list = next;
	}
	return(NULL);
}

/*
** Can be use for freeing a tetrimino structure
*/

void		free_tetris(t_etris *tetri)
{
	int y;

	y = 0;
	while (y < tetri->height)
	{
		ft_memdel((void **)(&(tetri->pos[y])));
		y++;
	}
	ft_memdel((void **)&(tetri->pos[y]));
	ft_memdel((void **)&tetri);
}

/*
** Use this fonction to create a new tetriminos structure
*/

t_etris		*tetris_new(char **pos, int width, int height, char value)
{
	t_etris		*tetris;

	tetris = ft_memalloc(sizeof(t_etris));
	tetris->pos = pos;
	tetris->value = value;
	tetris->height = height;
	tetris-> width = width;
	
	return (tetris);
}

/*
** Use this fonction to create a new point structure
*/

t_point		*point_new(int x,int y)
{
	t_point		*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}
