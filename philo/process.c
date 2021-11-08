/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:27:20 by tchariss          #+#    #+#             */
/*   Updated: 2021/07/29 20:19:04 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time(void)
{
	struct timeval	my;

	gettimeofday(&my, NULL);
	return (my.tv_sec * 1000 + my.tv_usec / 1000);
}

int	write_mes(int i, t_philiki *ph, int id)
{
	uint64_t	time;

	time = get_time() - ph->cen->start_time;
	if (pthread_mutex_lock(ph->cen->write_mut) != 0)
		return (1);
	if (i == 1)
		printf("\e[0;32;0;40m %llu ms |%d| has taken a fork\e[37;0m\n", time, id);
	else if (i == 2)
		printf("\e[38;5;218m %llu ms |%d| is eating\e[37m\n", time, id);
	else if (i == 3)
		printf("\e[38;5;110m %llu ms |%d| is sleeping\e[37m\n", time, id);
	else if (i == 4)
		printf("\e[36;221m %llu ms |%d| is thinking\e[37m\n", time, id);
	else if (i == 5)
	{
		printf("\e[38;5;194m %llu ms |%d| died\e[37m\n", time, id);
		return (-1);
	}
	if (pthread_mutex_unlock(ph->cen->write_mut) != 0)
		return (1);
	return (0);
}

int	eating(t_philiki *ph)
{
	size_t		time;

	if (pthread_mutex_lock(ph->r_fork) != 0)
		return (0);
	if (write_mes(1, ph, ph->id_p) == 1)
		return (0);
	if (pthread_mutex_lock(ph->l_fork) != 0)
		return (0);
	if (write_mes(1, ph, ph->id_p) == 1)
		return (0);
	if (write_mes(2, ph, ph->id_p) == 1)
		return (0);
	ph->begin_time = get_time();
	ph->max_time = ph->begin_time + ph->cen->time_die;
	time = get_time();
	while (get_time() <= time + ph->cen->time_eat)
		usleep(100);
	if (ph->cen->portion_eat != -2)
		ph->count++;
	if (pthread_mutex_unlock(ph->r_fork) != 0)
		return (0);
	if (pthread_mutex_unlock(ph->l_fork) != 0)
		return (0);
	return (1);
}

void	free_all(t_cen *cen)
{
	int	i;

	i = 0;
	if (cen->ph)
		free(cen->ph);
	if (cen->vilochki)
	{
		while (i < cen->philik_num)
		{
			if (cen->vilochki[i])
				free(cen->vilochki[i]);
			i++;
		}
		free(cen->vilochki);
	}
	if (cen->write_mut)
		free(cen->write_mut);
}
