/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:27:24 by tchariss          #+#    #+#             */
/*   Updated: 2021/07/29 19:27:25 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*potok_f(void *num_pot)
{
	t_philiki	*ph;
	size_t		time;

	ph = (t_philiki *)num_pot;
	ph->begin_time = get_time();
	while (1)
	{
		if (eating(ph) == 0)
			break ;
		if (ph->count == ph->cen->portion_eat)
		{
			ph->cen->how_many_count++;
			break ;
		}
		if (write_mes(3, ph, ph->id_p) == 1)
			break ;
		time = get_time();
		while (get_time() <= time + ph->cen->time_sleep)
			usleep(100);
		if (write_mes(4, ph, ph->id_p) == 1)
			break ;
	}
	return ((void *)(0));
}

int	init_vilochki(t_cen *cen)
{
	int	i;

	i = 0;
	while (i < cen->philik_num)
	{
		cen->vilochki[i] = malloc(sizeof(pthread_mutex_t));
		if (!cen->vilochki[i])
			return (-1);
		i++;
	}
	i = 0;
	while (i < cen->philik_num)
	{
		pthread_mutex_init(cen->vilochki[i], NULL);
		i++;
	}
	return (0);
}

int	init2(t_cen *cen, int i)
{
	while (i < cen->philik_num)
	{
		cen->ph[i].r_fork = cen->vilochki[i];
		if (i == cen->philik_num - 1)
			cen->ph[i].l_fork = cen->vilochki[0];
		else
			cen->ph[i].l_fork = cen->vilochki[i + 1];
		cen->ph[i].begin_time = get_time();
		cen->ph[i].count = 0;
		i++;
	}
	i = 0;
	cen->start_time = get_time();
	while (i < cen->philik_num)
	{
		cen->ph[i].id_p = i;
		pthread_create(&cen->ph[i].iden_p, NULL, &potok_f, &cen->ph[i]);
		i++;
		usleep(100);
	}
	return (0);
}

int	init(t_cen *cen)
{
	int	i;

	i = 0;
	cen->ph = malloc(sizeof(t_philiki) * cen->philik_num);
	cen->how_many_count = 0;
	while (i < cen->philik_num)
	{
		cen->ph[i].cen = cen;
		i++;
	}
	cen->write_mut = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!cen->write_mut)
		return (-1);
	pthread_mutex_init(cen->write_mut, NULL);
	cen->vilochki = (pthread_mutex_t **)malloc
		(sizeof(pthread_mutex_t *) * cen->philik_num);
	if (!cen->vilochki)
		return (-1);
	init_vilochki(cen);
	init2(cen, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cen		cen;

	cen.flag = 0;
	cen.ph_returns = 0;
	if (argc != 5 && argc != 6)
	{
		printf("\033[31m	неверное количество аргументов ;(\e[0m\n");
		return (-1);
	}
	if (check_arg(&cen, argc, argv) == -1)
		return (0);
	init(&cen);
	check_die(&cen);
	free_all(&cen);
	return (0);
}
