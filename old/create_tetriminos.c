/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:51:27 by qutrinh           #+#    #+#             */
/*   Updated: 2019/03/08 19:09:50 by qutrinh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			free_tetriminos(t_list *tetrimino_list)
{
	t_list			*elem;
	t_list			*tmp;

	elem = tetrimino_list;
	while (elem)
	{
		if (elem->content)
		{
			free((t_point *)((t_tetrimino *)elem->content)->p);
			free((t_tetrimino *)elem->content);
		}
		tmp = elem->next;
		free(elem);
		elem = tmp;
	}
}

static t_list	*empty_tetriminos(void)
{
	t_tetrimino		*new_tetri;
	t_list			*new;
	int				i;

	if(!(new_tetri = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
		return (NULL);
	if(!(new_tetri->p = (t_point *)malloc(sizeof(t_point) * 4)))
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		new_tetri->p[i].x = -1;
		new_tetri->p[i].y = -1;
		new_tetri->c = '0';
	}
	new = ft_lstnew(new_tetri, sizeof(t_tetrimino *));
	return (new);
}

static t_bool	read_file(int file, int tetriminos_nb, t_list **elem)
{
	t_list		*l_tetri;
	char		*str_tetri;

	l_tetri = empty_tetriminos();
	str_tetri = ft_strnew(21);
	if (l_tetri == NULL || str_tetri == NULL)
		return (false);
	if (read(file, str_tetri, 21) < 20)
	{
		free_tetriminos(l_tetri);
		free(str_tetri);
		*elem = NULL;
		if (str_tetri[0] == '\0')
			return (true);
		return (false);
	}
	if (read_tetriminos(l_tetri, str_tetri, 'A' + tetriminos_nb) == false)
		return (false);
	free(str_tetri);
	*elem = l_tetri;
	return (true);
}

static int		get_tetriminos_init(char **av)
{
	int		file;

	file = open(av[1], O_RDONLY);
	if (file == -1 || validate_file(file) == false)
		return (-1);
	close(file);
	file = open(av[1], O_RDONLY);
	if (file == -1)
		return (-1);
	return (file);
}

t_list			*get_tetriminos(char **av)
{
	int		file;
	t_list	*tetri_list;
	t_list	*tetri_elem;
	int		tetriminos_nb;

	file = get_tetriminos_init(av);
	if (file == -1)
		return (NULL);
	tetriminos_nb = 0;
	if (read_file(file, tetriminos_nb, &(tetri_elem)) == false)
		return (NULL);
	tetri_list = tetri_elem;
	while (tetri_elem != NULL)
	{
		tetriminos_nb++;
		if (read_file(file, tetriminos_nb, &(tetri_elem->next)) == false)
			return (NULL);
		tetri_elem = tetri_elem->next;
	}
	if (tetriminos_nb > 26)
		return (NULL);
	return (tetri_list);
}
