/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:57:56 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/14 20:48:32 by gjuste           ###   ########.fr       */
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
	char			**pipe;
	struct s_room	*next;
}				t_room;

typedef struct	s_lem
{
	int		ants;
	int		opt;
	char	*start;
	char	*end;
	t_room	*r;
}				t_lem;

void			ft_error(t_lem *stt, int err);
void			parser(t_lem *stt);
void			check_cmd(t_lem *stt, char *line);
int				room_fmt(t_lem *stt, char *line);
int				get_pipe(t_lem *stt, char *line);

#endif
