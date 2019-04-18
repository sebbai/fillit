/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynaamane <ynaamane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 23:08:40 by qutrinh           #+#    #+#             */
/*   Updated: 2019/03/21 16:44:32 by ynaamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** return the nb of tetrimino pieces
** in the list (should be anywhere between 1 and 26) :
*/

int			get_tetriminos_nb(t_list *tetriminos)
{
	int		i;

	i = 0;
	while (tetriminos != NULL)
	{
		i++;
		tetriminos = tetriminos->next;
	}
	return (i);
}

/*
** Number of ways a piece can be put on an empty board
*/

int			get_positions_nb(t_tetrimino *t, int board_size)
{
	int		positions_nb;
	t_point	p;

	positions_nb = 0;
	p.y = -1;
	while (++p.y < board_size)
	{
		p.x = -1;
		while (++p.x < board_size)
		{
			if (can_be_placed(t, p, board_size) == true)
				positions_nb++;
		}
	}
	return (positions_nb);
}

t_point		*point_new(int x, int y)
{
	t_point		*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return(point);
}

// t_etris		*tetris_new(char **pos, int width, int height, char value)
// {
// 	t_etris		*tetris;

// 	tetris = ft_memalloc(sizeof(t_etris));
// 	tetris->pos = pos;
// 	tetris->height = height;
// 	tetris->value = value;
// 	tetris->width = width;
// 	return(tetris);
// }
