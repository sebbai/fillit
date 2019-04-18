/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <qutrinh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 03:40:29 by qutrinh           #+#    #+#             */
/*   Updated: 2019/03/11 04:18:05 by qutrinh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** fills the matrix with 0's and 1's (starting position) :
*/

static void		fill_matrix_v1(t_matrix *matrix, int row, int piece_col,
		t_point current_p)
{
	int			col;

	col = get_column_index(current_p.x, current_p.y,
			matrix->board_size);
	matrix->m[row][col] = 1;
	matrix->m[row][piece_col] = 1;
}

static void		fill_matrix_v2(t_matrix *matrix, int piece_col,
		int *arr, t_tetrimino *t)
{
	int			j;
	int			origin_x;
	int			origin_y;
	t_point		current_p;

	current_p = get_position_n(t, arr[1], matrix->board_size);
	origin_x = current_p.x;
	origin_y = current_p.y;
	j = 0;
	while (j++ < 4)
	{
		fill_matrix_v1(matrix, arr[0], piece_col, current_p);
		current_p.x = origin_x + t->p[j].x;
		current_p.y = origin_y + t->p[j].y;
	}
}

void			fill_matrix(t_matrix *matrix, t_list *tetriminos, int hole_nb)
{
	int			i;
	int			row;
	int			arr[2];
	int			piece_col;
	t_tetrimino *t;

	row = 0;
	arr[0] = row;
	piece_col = matrix->board_size * matrix->board_size;
	while (tetriminos != NULL)
	{
		i = 0;
		t = (t_tetrimino *)tetriminos->content;
		while (++i <= get_positions_nb(t, matrix->board_size))
		{
			arr[1] = i;
			fill_matrix_v2(matrix, piece_col, arr, t);
			arr[0]++;
			row++;
		}
		piece_col++;
		tetriminos = tetriminos->next;
	}
	if (hole_nb > 0)
		fill_holes(matrix, hole_nb, row, piece_col);
}

/*
** fill the matrix with holes
*/

void			fill_holes(t_matrix *matrix,
		int hole_nb, int row, int piece_col)
{
	int			col;

	while (hole_nb > 0)
	{
		col = 0;
		while (col < matrix->board_size * matrix->board_size)
		{
			matrix->m[row][col] = 1;
			matrix->m[row][piece_col] = 1;
			row++;
			col++;
		}
		piece_col++;
		hole_nb--;
	}
}
