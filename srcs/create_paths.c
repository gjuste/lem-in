/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:13:37 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/08 13:32:57 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

// t_pdata	*new_path(void)
// {
// 	t_pdata	*new;

// 	if (!(new = (t_pdata*)malloc(sizeof(t_pdata))))
// 		return (NULL);
// 	new->ratio = 0;
// 	new->nb_r = 0;
// 	new->p = NULL;
// 	new->next = NULL;
// 	return (new);
// }

// int		check_start(t_links *l)
// {
// 	// ft_printf("OUI || ");
// 	while (l)
// 	{
// 		if (l->i)
// 			return (1);
// 		l = l->next;
// 	}
// 	// ft_printf("oui\n");
// 	return (0);
// }

// t_path	*new_p(t_room *r)
// {
// 	t_path	*new;

// 	if (!(new = (t_path*)malloc(sizeof(t_path))))
// 		return (NULL);
// 	new->r = r;
// 	new->ants = 0;
// 	new->next = NULL;
// 	return (new);
// }

// int		get_path(t_lem *stt, t_room *room)
// {
// 	t_links	*lnk;
// 	int		*i;

// 	lnk = room->links;

// 	while (lnk)
// 	{
// 		if (lnk->i == 1)
// 		{
// 			*i = 0;
// 			get_complete_path(stt, lnk->r, i);
// 		}
// 		lnk = lnk->next;
// 	}
//     return (0);
// }

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
