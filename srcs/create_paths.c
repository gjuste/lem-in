/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:13:37 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/15 15:37:31 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_complete_path(t_lem *stt, t_room *room, int *i)
{
	t_links	*lnk;

	(*i)++;
	lnk = room->links;
	while (lnk && lnk->i != 1)
		lnk = lnk->next;
	if (lnk && lnk->r != stt->end)
		get_complete_path(stt, lnk->r, i);
	room->nb_r = *i;
	return (0);
}

int		create_paths(t_lem *stt)
{
	t_links	*lnk;
	int		i;
	int		j;

	lnk = stt->start->links;
	j = 0;
	while (lnk)
	{
		if (lnk->i == 1)
		{
			i = 1;
			get_complete_path(stt, lnk->r, &i);
			if (stt->min == 0 || i < stt->min)
				stt->min = i;
			stt->p_size[j] = lnk->r;
			j++;
		}
		lnk = lnk->next;
	}
	return (0);
}
