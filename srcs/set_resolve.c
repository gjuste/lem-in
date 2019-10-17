/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_resolve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 02:22:44 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/17 13:41:22 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	start_end_travel(t_lem *stt, t_room *start, t_room *end)
{
	start->ants = stt->ants;
	while (start->ants > 0)
	{
		start->ants--;
		end->ants++;
		ft_printf("L%d-%s ", end->ants, end->name);
	}
	stt->l_nb++;
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
			print_parse(stt);
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

void		sort_p_size(t_lem *stt)
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

int			set_resolve(t_lem *stt)
{
	int		ret;

	ret = 0;
	if (!stt->start || !stt->end)
		return (-1);
	if (check_start_end(stt))
		return (0);
	while ((ret = bfs(stt)) == 0)
		stt->p_nb++;
	if (ret == -1 || !stt->p_nb)
		return (-1);
	if (creat_p_size(stt) == -1)
		return (-1);
	if (create_paths(stt) == -1)
		return (-1);
	sort_p_size(stt);
	print_parse(stt);
	if (resolve(stt) == -1)
		return (-1);
	return (0);
}
