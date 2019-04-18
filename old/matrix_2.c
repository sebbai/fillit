/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <qutrinh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 01:09:02 by qutrinh           #+#    #+#             */
/*   Updated: 2019/03/11 04:04:16 by qutrinh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Translate 2 dimension matrix coordinates to matrix' column's index
*/

int			get_column_index(int x, int y, int board_size)
{
	return (y * board_size + x);
}

void		print_matrix(t_matrix matrix)
{
	int		row;
	int		col;
	int		i;

	row = 0;
	while (row < matrix.rows_nb)
	{
		col = 0;
		while (col < matrix.cols_nb)
		{
			if (matrix.m[row][col] == 1)
				printf(" \033[32m%d\033[0m ", matrix.m[row][col]);
			else if (matrix.m[row][col] == 0)
				printf(" \033[31m%d\033[0m ", matrix.m[row][col]);
			else
				printf(" %d ", matrix.m[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
}

t_point		get_position_n(t_tetrimino *t, int n, int board_size)
{
	t_point	p;
	int		position_nb;

	p.y = -1;
	position_nb = 0;
	while (++p.y < board_size)
	{
		p.x = -1;
		while (++p.x < board_size)
		{
			if (can_be_placed(t, p, board_size) == true)
			{
				position_nb++;
				if (position_nb == n)
					return (p);
			}
		}
	}
	return (p);
}

void		free_matrix(t_matrix *matrix)
{
	int		i;

	if (matrix != NULL)
	{
		i = -1;
		while (++i < matrix->rows_nb)
		{
			if (matrix->m[i] != NULL)
				free(matrix->m[i]);
		}
		free(matrix->m);
		free(matrix);
	}
}
