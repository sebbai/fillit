/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:50:42 by sebbaill          #+#    #+#             */
/*   Updated: 2018/12/18 19:06:22 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	int		cpi;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			cpi = i;
			while (str[i++] == to_find[j++])
			{
				if (to_find[j] == '\0')
					return ((char*)&str[cpi]);
			}
			j = 0;
			i = cpi;
		}
		i++;
	}
	return (0);
}
