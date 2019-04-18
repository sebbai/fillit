/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qutrinh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:34:12 by qutrinh           #+#    #+#             */
/*   Updated: 2019/02/15 22:20:17 by qutrinh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Count lines and columns for each tetrimino
*/

static t_bool	validate_count(char *tetri)
{
	int		line;
	int		col;
	int		i;

	line = 0;
	i = 0;
	while (tetri[i] != 0 && i < 20)
	{
		col = 0;
		while (tetri[i] != '\n' && tetri[i] != '\0')
		{
			col++;
			i++;
		}
		if (col != 4)
			return (false);
		i++;
		line++;
	}
	if (line != 4 || (tetri[20] != '\n' && tetri[20] != '\0'))
		return (false);
	return (true);
}

/*
** Get tetrimino as a string from file
*/

static char		*get_21(int fd)
{
	char	*str;
	int		ret;

	str = ft_strnew(21);
	ret = read(fd, str, 21);
	if (str == NULL || (ret != 21 && str[20] != '\0'))
		return (NULL);
	return (str);
}

/*
** Validate pattern by compare with library of patterns
*/

static t_bool	validate_pattern(char *tetri, char *pattern)
{
	char	*simplified;
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = -1;
	simplified = ft_strnew(17);
	while (++i < 20)
	{
		if ((tetri[i] != '\n' && tetri[i] != '\0' && tetri[i] != '.'
					&& tetri[i] != '#') || (tetri[i] == '\n' &&
					tetri[i - 1] == '#' && tetri[i + 1] == '#'))
			return (false);
		if (tetri[i] != '\n')
			simplified[++j] = tetri[i];
	}
	if (ft_charcount('#', simplified) != 4)
		return (false);
	tmp = ft_strstr(simplified, pattern);
	if (tmp == NULL || ft_strlen(pattern) == 0 || pattern == NULL)
		return (false);
	free(simplified);
	return (true);
}

/*
** Aggregate all validations
*/

static t_bool	validate(char *tetri)
{
	int		i;
	char	*tmp;

	i = -1;
	if (validate_count(tetri) == false)
		return (false);
	while (i++ < 18)
	{
		tmp = get_pattern(i);
		if (validate_pattern(tetri, tmp) == true)
		{
			free(tmp);
			break ;
		}
		free(tmp);
	}
	if (i > 18)
		return (false);
	return (true);
}

/*
** Validate if there are more than 26 pieces and validate each piece
*/

t_bool			validate_file(int fd)
{
	int		i;
	char	*tetri;

	i = 0;
	while (i++ <= 25)
	{
		tetri = get_21(fd);
		if (tetri == NULL || validate(tetri) == false)
		{
			printf("\n%s\n", tetri);
			return (false);
		}
		if (tetri[20] == '\0')
		{
			free(tetri);
			return (true);
		}
		free(tetri);
	}
	return (false);
}
