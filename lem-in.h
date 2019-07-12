/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:57:56 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/12 21:39:41 by gjuste           ###   ########.fr       */
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
}				t_lem;

int		parser(t_lem *stt);
void	ft_error(t_lem *stt, int err);

#endif
