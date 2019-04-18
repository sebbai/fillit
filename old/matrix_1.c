/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <qutrinh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 00:54:11 by qutrinh           #+#    #+#             */
/*   Updated: 2019/03/11 01:40:04 by qutrinh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
**	Get the number of rows for the matrix (number of positions 
**	a piece can be placed)
*/

static int		get_rows_nb(t_list *tetriminos, int bsize)
{
	int			rows_nb;

	rows_nb = 0;
	while (tetriminos)
	{
		rows_nb += get_positions_nb((t_tetrimino *)tetriminos->content, bsize);
		tetriminos = tetriminos->next;
	}
	return (rows_nb);
}

/*
** Allocate memory for an empty matrix
*/

static t_matrix	*allocate_memory(t_list *tetriminos,
		int cols_nb, int rows_nb, int bsize)
{
	t_matrix	*matrix;

	if (!(matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	matrix->board_size = bsize;
	matrix->cols_nb = cols_nb;
	matrix->rows_nb = rows_nb;
	matrix->tetri_nb = get_tetriminos_nb(tetriminos);
	return (matrix);
}

/*
** Create an empty matrix
*/

t_matrix		*create_matrix(t_list *tetriminos, int bsize, int hole_nb)
{
	int			cols_nb;
	int			rows_nb;
	t_matrix	*matrix;
	int			i;
	t_point		p;

	cols_nb = get_tetriminos_nb(tetriminos) + (bsize * bsize) + hole_nb;
	rows_nb = get_rows_nb(tetriminos, bsize);
	if (hole_nb > 0)
		rows_nb += bsize * bsize * hole_nb;
	if (!(matrix = allocate_memory(tetriminos, cols_nb, rows_nb, bsize)))
		return (NULL);
	cols_nb++;
	if (!(matrix->m = (int **)malloc(sizeof(int *) * ++rows_nb)))
		return (NULL);
	i = -1;
	while (++i < rows_nb)
	{
		if (!(matrix->m[i] = (int *)malloc(sizeof(int) * cols_nb)))
			return (NULL);
		p.x = -1;
		while (++p.x < cols_nb)
			matrix->m[i][p.x] = 0;
	}
	return (matrix);
}
