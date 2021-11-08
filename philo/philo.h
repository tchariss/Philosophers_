/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:27:19 by tchariss          #+#    #+#             */
/*   Updated: 2021/07/29 19:27:20 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_cen
{
	pthread_mutex_t		**vilochki;
	pthread_mutex_t		*write_mut;
	pthread_mutex_t		*block_eat;
	int					philik_num;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					flag;
	int					portion_eat;
	int					how_many_count;
	int					ph_returns;
	uint64_t			start_time;
	struct s_philiki	*ph;
}				t_cen;

typedef struct s_philiki
{
	pthread_t		iden_p;
	int				id_p;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	uint64_t		begin_time;
	uint64_t		max_time;
	int				count;
	t_cen			*cen;
}				t_philiki;

int				init(t_cen *cen);
int				init2(t_cen *cen, int i);
int				init_vilochki(t_cen *cen);
void			*potok_f(void *num_pot);
int				eating(t_philiki *ph);
int				write_mes(int i, t_philiki *ph, int id);
uint64_t		get_time(void);
void			check_die(t_cen *cen);
int				check_err_f(int ac, char **av);
int				check_arg(t_cen *cen, int ac, char **av);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);
int				ft_isdigit(char *s);
void			free_all(t_cen *cen);

#endif
