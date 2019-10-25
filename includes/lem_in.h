/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:57:56 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/17 13:20:37 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include "colors.h"
# include "options.h"

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

typedef struct	s_str
{
	char			*line;
	struct s_str	*next;
}				t_str;

typedef struct	s_lem
{
	int		ants;
	int		p_ants;
	int		opt;
	int		min;
	int		avp;
	int		sim;
	int		p_nb;
	int		l_nb;
	int		l_need;
	int		errstr;
	t_str	*str;
	t_str	*lstr;
	t_room	**p_size;
	t_room	*start;
	t_room	*end;
	t_room	*r;
}				t_lem;

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
int				set_resolve(t_lem *stt);
int				bfs(t_lem *stt);
int				do_simulation(t_lem *stt, t_queue *q, t_links *lnk);
int				create_paths(t_lem *stt);
void			remove_connection(t_lem *stt, t_room *r1, t_room *r2);
char			*join(t_lem *stt, t_str **lstr, char *line);
void			print_parse(t_lem *stt);
void			print_help(void);
void			print_parse(t_lem *stt);
int				get_complet_path(t_lem *stt, t_room *room);
void			print_path(t_lem *stt);

#endif
