/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:57:56 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/16 16:38:28 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	struct s_room	**links;
	struct s_room	*next;
}				t_room;

// typedef struct	s_queue
// {
// 	t_room			*r;
//     int             marqueur;
// 	struct s_queue	*next;
// }				t_queue;

typedef struct	s_lem
{
	int		ants;
	int		opt;
	t_room	*start;
	t_room	*end;
	t_room	*r;
}				t_lem;

void			ft_error(t_lem *stt, int err);
int				parser(t_lem *stt);
int				check_cmd(t_lem *stt, char *line);
int				room_fmt(t_lem *stt, char *line);
int				get_pipe(t_lem *stt, char *line);
void			free_all(t_lem *stt);
void			ft_print_stt(t_lem *stt);

#endif
