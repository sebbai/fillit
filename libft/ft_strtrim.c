/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:50:42 by sebbaill          #+#    #+#             */
/*   Updated: 2019/01/22 18:39:49 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int		i;
	int		j;
	int		len;
	int		end;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	end = len;
	while (((s[i] == '\t') || (s[i] == '\n') || (s[i] == ' ')) && ((s[i])))
		i++;
	if (i == end)
		return (ft_strdup(""));
	j = i;
	while ((s[--end] == '\t') || (s[end] == '\n') || (s[end] == ' '))
		j++;
	if (!(str = ft_strsub(s, i, len - j)))
		return (NULL);
	return (str);
}
