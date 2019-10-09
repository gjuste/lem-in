/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_resolve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 02:22:44 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/09 16:42:34 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	start_end_travel(t_lem *stt, t_room *start, t_room *end)
{
	start->ants = stt->ants;
	ft_printf("\n");
	while (start->ants > 0)
	{
		start->ants--;
		end->ants++;
		ft_printf("L%d-%s ", end->ants, end->name);
	}
	ft_printf("\n");
}

static int	check_start_end(t_lem *stt)
{
	t_links	*tmp;

	tmp = stt->start->links;
	while (tmp)
	{
		if (tmp->r == stt->end)
		{
			start_end_travel(stt, stt->start, stt->end);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static int	creat_p_size(t_lem *stt)
{
	int		i;

	i = 0;
	if (!(stt->p_size = (t_room**)malloc(sizeof(t_room*) * (stt->p_nb + 1))))
		return (-1);
	while (i <= stt->p_nb)
	{
		stt->p_size[i] = NULL;
		i++;
	}
	return (0);
}

void		sort_p_size(t_lem *stt)  // changer retour si probleme
{
	t_room	*save;
	int		i;
	int		j;

	i = 0;
	while (i < stt->p_nb - 1)
	{
		j = i + 1;
		while (j < stt->p_nb)
		{
			if (stt->p_size[j]->nb_r < stt->p_size[i]->nb_r)
			{
				save = stt->p_size[i];
				stt->p_size[i] = stt->p_size[j];
				stt->p_size[j] = save;
			}
			j++;
		}
		i++;
	}
}

void		set_resolve(t_lem *stt)
{
	if (check_start_end(stt))
		return ;
	while (bfs(stt) == 0) //semble avoir un truc pas free par free_queue
		stt->p_nb++;
	if (creat_p_size(stt) == -1)
		return ;
	if (create_paths(stt) == -1)
		ft_printf("OOOOOOHHHHH\n");
	sort_p_size(stt);
	if (resolve(stt) == -1)
		ft_printf("\n%sERROR2%s\n", BR, RS);
}
