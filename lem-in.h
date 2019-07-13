/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:57:56 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/14 00:27:45 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct	s_lem
{
	int		ants;
	int		opt;
	char	*start;
	char	*end;
	char	*pipe;
}				t_lem;

void			ft_error(t_lem *stt, int err);
void			parser(t_lem *stt);
void			check_cmd(t_lem *stt, char *line);
int				room_fmt(char *line);
int				get_pipe(t_lem *stt, char *line);
int				pipe_fmt(char *line);

#endif
