/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:18:58 by jpelleti          #+#    #+#             */
/*   Updated: 2019/10/17 13:22:51 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_parse(t_lem *stt)
{
	t_str	*tmp;
	int		i;

	tmp = stt->str;
	i = 0;
	while (!i && tmp)
	{
		ft_printf("%s\n", tmp->line);
		tmp = tmp->next;
		if (tmp && !tmp->next && stt->errstr)
			i = 1;
	}
	ft_printf("\n");
}

int			get_complet_path(t_lem *stt, t_room *room)
{
	t_links	*lnk;

	lnk = room->links;
	if (room == stt->end)
		ft_printf("%s%s%s", BW, room->name, RS);
	else
		ft_printf("%s%s%s || ", BG, room->name, RS);
	while (lnk && lnk->i != 1)
		lnk = lnk->next;
	if (room != stt->end)
		get_complet_path(stt, lnk->r);
	return (0);
}

void		print_path(t_lem *stt)
{
	t_links *lnk;

	ft_printf("\n%sPaths found :%s\n", BW, RS);
	lnk = stt->start->links;
	while (lnk)
	{
		if (lnk->i == 1)
		{
			ft_printf("rooms in this path : %s%d%s\n", C, lnk->r->nb_r, RS);
			ft_printf("%s%s%s || ", BW, stt->start->name, RS);
			get_complet_path(stt, lnk->r);
			ft_printf("\n");
		}
		lnk = lnk->next;
	}
}
