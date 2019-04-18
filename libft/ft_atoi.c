/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebbaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:13:32 by sebbaill          #+#    #+#             */
/*   Updated: 2019/01/22 13:26:20 by sebbaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		i;
	int		n;
	long	result;

	i = 0;
	n = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	if ((str[i - 1] == '-') && (str[i] > 47) && (str[i] < 58))
		n = -1;
	while ((str[i]) > 47 && (str[i] < 58))
	{
		if (result * 10 < 0)
			return ((n == -1) ? 0 : -1);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (n * result);
}
