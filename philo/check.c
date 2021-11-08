/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:27:25 by tchariss          #+#    #+#             */
/*   Updated: 2021/07/29 19:27:29 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_die(t_cen *cen)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < cen->philik_num)
		{
			if (cen->how_many_count == cen->philik_num)
				break ;
			if (cen->ph[i].max_time - cen->start_time < get_time()
				- cen->start_time)
			{
				if (write_mes(5, cen->ph, cen->ph->id_p) == 1)
					return ;
				cen->flag = 1;
				break ;
			}
			i++;
		}
		if (cen->flag == 1 || cen->how_many_count == cen->philik_num)
			break ;
	}
}

int	check_err_f(int ac, char **av)
{
	int	num;
	int	one_arg;

	one_arg = ft_atoi(av[1]);
	num = ac - 1;
	while (num > 0)
	{
		if (ft_isdigit(av[num]) == -1)
		{
			printf("\033[31m	принимаю только адекватные циферки :(\e[0m\n");
			return (-1);
		}
		num--;
	}
	if (one_arg < 2)
	{
		printf("\033[31mя не могу один есть, где все :(\e[0m\n");
		printf("\e[38;5;194m %d ms |0| died \e[37m\n", ft_atoi(av[2]) + 1);
		return (-1);
	}
	return (0);
}

int	check_arg(t_cen *cen, int ac, char **av)
{
	if (check_err_f(ac, av) == -1)
		return (-1);
	cen->philik_num = ft_atoi(av[1]);
	cen->time_die = ft_atoi(av[2]);
	cen->time_eat = ft_atoi(av[3]);
	cen->time_sleep = ft_atoi(av[4]);
	if (av[5])
		cen->portion_eat = ft_atoi(av[5]);
	else
		cen->portion_eat = -2;
	return (0);
}
