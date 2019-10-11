/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:57:56 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/11 17:26:45 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define R "\033[31m"
# define G "\033[32m"
# define Y "\033[33m"
# define B "\033[34m"
# define P "\033[35m"
# define C "\033[36m"
# define BR "\033[31;1m"
# define BG "\033[32;1m"
# define BY "\033[33;1m"
# define BB "\033[34;1m"
# define BP "\033[35;1m"
# define BC "\033[36;1m"
# define BW "\033[1m"
# define RS "\033[0m"


# include "libft/libft.h"

typedef struct	s_links
{
	struct s_room	*r;
	int				i;
	struct s_links	*next;
}				t_links;

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	int				ants;
	int				marque;
	int				bfs;
	int				done;
	int				nb_r;
	t_links			*links;
	struct s_room	*next;
	struct s_room	*parent;
}				t_room;

typedef struct	s_queue
{
	int				i;
	t_room			*r;
	struct s_queue	*next;
}				t_queue;

typedef struct	s_lem
{
	int		ants;
	int		opt;
	int		min;
	int		avp;
	int		sim;
	int		p_nb;
	int		l_nb;
	int		l_need;
	t_room	**p_size;
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
void			free_links(t_links *l);
void			ft_print_stt(t_lem *stt);
int				resolve(t_lem *stt);
int				do_path(t_lem *stt);
void			free_queue(t_queue *q);
void			set_resolve(t_lem *stt);
int				bfs(t_lem *stt);
int				create_paths(t_lem *stt);
void			remove_connection(t_lem *stt, t_room *r1, t_room *r2);

#endif
