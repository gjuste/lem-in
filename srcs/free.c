/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:13:50 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/16 13:42:55 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	free_room(t_room *r)
{
	if (r)
	{
		ft_strdel(&(r->name));
		if (r->links)
			free(r->links);
		r->links = NULL;
		free_room(r->next);
		free(r);
		r = NULL;
	}
}

void		free_all(t_lem *stt)
{
	stt->start = NULL;
	stt->end = NULL;
	free_room(stt->r);
	free(stt);
	stt = NULL;
}
