/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:26:58 by jpelleti          #+#    #+#             */
/*   Updated: 2019/10/17 13:28:25 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	start_travel_ants(t_lem *stt, t_room *room, t_room *prev)
{
	prev->ants--;
	room->ants = stt->ants - prev->ants;
	if (stt->p_ants && room->ants == stt->p_ants)
		ft_printf("%sL%d%s-%s ", R, room->ants, RS, room->name);
	else
		ft_printf("L%d-%s ", room->ants, room->name);
}

static void	travel_ants(t_lem *stt, t_room *room, t_room *prev)
{
	if (room == stt->end)
		room->ants++;
	else
		room->ants = prev->ants;
	if (stt->p_ants && prev->ants == stt->p_ants)
		ft_printf("%sL%d%s-%s ", R, prev->ants, RS, room->name);
	else
		ft_printf("L%d-%s ", prev->ants, room->name);
	prev->ants = 0;
}

static int	travel(t_lem *stt, t_room *room, t_room *prev, int ind)
{
	t_links	*lnk;

	lnk = room->links;
	while (lnk && room != stt->end)
	{
		if (lnk->i == 1)
		{
			if (travel(stt, lnk->r, room, ind) == -1)
				return (-1);
			if (room != stt->start)
				break ;
		}
		lnk = lnk->next;
	}
	if (room != stt->start && prev->ants > 0)
	{
		if (room->ants && room != stt->end)
			return (-1);
		if (prev == stt->start && ind)
			start_travel_ants(stt, room, prev);
		else if (prev != stt->start)
			travel_ants(stt, room, prev);
	}
	return (0);
}

int			start_it(t_lem *stt)
{
	int		i;
	int		diff;
	int		total;
	int		ind;

	i = 0;
	total = 0;
	while (stt->p_size[i])
	{
		diff = 0;
		ind = 1;
		if (i >= 1)
			diff = stt->p_size[i]->nb_r - stt->p_size[i - 1]->nb_r;
		total += diff * i;
		if (total > stt->start->ants)
			ind = 0;
		if (travel(stt, stt->p_size[i], stt->start, ind) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int			resolve(t_lem *stt)
{
	int		save;

	stt->start->ants = stt->ants;
	while (stt->end->ants < stt->ants)
	{
		save = stt->start->ants;
		if (start_it(stt) == -1)
			return (-1);
		if (stt->start->ants != 0 && stt->start->ants == save)
			return (-1);
		ft_printf("\n");
		stt->l_nb++;
	}
	return (0);
}
