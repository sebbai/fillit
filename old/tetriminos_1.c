/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <qutrinh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 21:45:08 by qutrinh           #+#    #+#             */
/*   Updated: 2019/03/10 22:57:28 by qutrinh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
**	Find a point on a board and return its pointer
*/

t_point		*find_point(int x, int y, t_board board)
{
	int		i;

	i = 0;
	while (board.p[i].c)
	{
		if (board.p[i].x == x && board.p[i].y == y)
			return (&board.p[i]);
		i++;
	}
	return (&board.p[i]);
}

/*
**	Check if a piece can be placed on an empty board at a given point
*/

t_bool		can_be_placed(t_tetrimino *t, t_point p, int board_size)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if ((p.x + t->p[i].x) < 0 || (p.x + t->p[i].x) >= board_size ||
			(p.y + t->p[i].y) < 0 || (p.y + t->p[i].y) >= board_size)
			return (false);
	}
	return (true);
}

/*
**	Place a given tetrimino on a board at a given point
*/

t_board		put_tetrimino(t_point p, t_tetrimino t, t_board board)
{
	int		i;
	t_board	old_board;
	t_point	*current_p;
	t_point	*start_p;

	i = 0;
	old_board = dup_board(board);
	start_p = find_point(p.x, p.y, board);
	current_p = start_p;
	while (i < 4)
	{
		if (current_p->c == '.')
			current_p->c = t.c;
		else
		{
			free(board.p);
			return (old_board);
		}
		i++;
		current_p =
			find_point(start_p->x + t.p[i].x, start_p->y + t.p[i].y, board);
	}
	free(old_board.p);
	return (board);
}
