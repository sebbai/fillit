/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:04:08 by sebbaill          #+#    #+#             */
/*   Updated: 2018/12/13 20:52:14 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	if (s1[i] == '\0')
	{
		while (s2[j] != '\0')
			s1[i++] = s2[j++];
		s1[i] = '\0';
	}
	return (s1);
}
