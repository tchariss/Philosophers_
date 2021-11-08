/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:27:42 by tchariss          #+#    #+#             */
/*   Updated: 2021/07/29 19:27:43 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	size_t			i;
	unsigned long	res;
	int				b;

	i = 0;
	res = 0;
	b = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			b = -1;
	while (str[i] >= 48 && str[i] <= 57)
		res = res * 10 + (str[i++] - '0');
	if (res > 9223372036854775807)
	{
		if (b == 1)
			return (-1);
		return (0);
	}
	return (b * res);
}

int	ft_isdigit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (-1);
		i++;
	}
	return (0);
}
