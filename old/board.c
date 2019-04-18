/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <qutrinh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 04:57:27 by qutrinh           #+#    #+#             */
/*   Updated: 2019/03/10 22:55:06 by qutrinh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		print_board(t_board board)
{
	int		i;
	int		row;
	int		col;

	i = 0;
	row = 0;
	while (i < board.size * board.size)
	{
		col = 0;
		while (col++ < board.size)
			ft_putchar(board.p[i++].c);
		ft_putchar('\n');
		row++;
	}
}

t_board		create_new_board(int size)
{
	t_board	new_board;
	int		row;
	int		col;
	int		i;

	new_board.size = size;
	new_board.p = (t_point *)malloc(sizeof(t_point) * size * size);
	i = 0;
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			new_board.p[i].c = '.';
			new_board.p[i].x = col;
			new_board.p[i].y = row;
			i++;
			col++;
		}
		row++;
	}
	return (new_board);
}

t_bool	cmp_board(t_board board1, t_board board2)
{
	int		i;

	if (board1.size != board2.size)
		return (false);
	i = 0;
	while (board1.p[i].c)
	{
		if (board1.p[i].c != board2.p[i].c)
			return (false);
		i++;
	}
	return (true);
}

t_board		dup_board(t_board board)
{
	int		i;
	t_board	new_board;

	i = -1;
	new_board = create_new_board(board.size);
	while (++i < board.size * board.size)
		new_board.p[i].c = board.p[i].c;
	return (new_board);
}

int			get_hole_nb(t_list *tetriminos, int board_size)
{
	int		hole_nb;

	hole_nb = board_size * board_size - get_tetriminos_nb(tetriminos) * 4;
	if (hole_nb < 0)
		hole_nb = 0;
	return (hole_nb);
}
