/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:51:58 by qutrinh           #+#    #+#             */
/*   Updated: 2019/03/09 18:46:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		adjust(t_tetrimino *tetri, t_point upper_left)
{
	int			i;

	i = -1;
	while (++i < 4)
	{
		tetri->p[i].x = tetri->p[i].x - upper_left.x;
		tetri->p[i].y = tetri->p[i].y - upper_left.y;
	}
}

static void		init(t_point *p, int *a, int *b)
{
	p->x = 0;
	p->y = 0;
	*a = -1;
	*b = 0;
}

t_bool			read_tetriminos(t_list *tetriminos, char *tetri_str, char c)
{
	t_point		point;
	int			i;
	int			square_index;
	t_tetrimino	*t;

	init(&point, &i, &square_index);
	t = (t_tetrimino *)tetriminos->content;
	while (tetri_str[++i])
	{
		if (tetri_str[i] == '#')
		{
			t->p[square_index] = set_point(point.x, point.y);
			t->c = c;
			if (++square_index > 4)
				return (false);
		}
		point.x++;
		if (tetri_str[i] == '\n')
		{
			point.x = 0;
			point.y++;
		}
	}
	adjust(t, t->p[0]);
	return (true);
}
/*
** For debugging only. To be deleted.
*/
void			print_tetriminos(t_list *tetriminos)
{
	t_list		*tmp;
	int			i;
	int			x;
	int			y;

	tmp = tetriminos;
	while (tmp)
	{
		y = 0;
		i = 0;
		print_tetrimino(*(t_tetrimino *)tmp->content);
		printf("----------------\n");
		tmp = tmp->next;
	}
	free(tmp);
}

void			print_tetrimino(t_tetrimino tetrimino)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	y = 0;
	while (tetrimino.p && y < 4 && i < 4)
	{
		x = -1;
		while (x < 3)
		{
			if (x == tetrimino.p[i].x && y == tetrimino.p[i].y)
			{
				printf("#");
				i++;
			}
			else
				printf(" ");
			x++;
		}
		y++;
		printf("\n");
	}
}
