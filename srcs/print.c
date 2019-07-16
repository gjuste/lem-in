/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:20:24 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/16 13:32:08 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	print_ants(t_lem *stt)
{
	ft_printf("\n");
	ft_printf("ants : \033[32m%d\033[0m\n", stt->ants);
}

void    print_start_end(t_lem *stt)
{
	ft_printf("\n");
	if (stt->start)
		ft_printf("start : \033[32m%s\033[0m  ||  ", stt->start->name);
	else
		ft_printf("\033[31mno start\033[0m  ||  ");
	if (stt->end)
		ft_printf("end : \033[32m%s\033[0m\n", stt->end->name);
	else
		ft_printf("\033[31mno end\033[0m\n");
}

void	print_r(t_lem *stt)
{
	int		j;
	t_room	*tmp;

	ft_printf("\n");
	tmp = stt->r;
	while (tmp)
	{
		j = 0;
		ft_printf("room : \033[35m%-3s\033[0m |  \033[36m%3d\033[0m / \033[34m%3d\033[0m  ||", tmp->name, tmp->x, tmp->y);
		while (tmp->links && tmp->links[j])
		{
			ft_printf("  \033[33m%s\033[0m", tmp->links[j]->name);
			j++;
		}
		if (!tmp->links)
			ft_printf("\033[31m  no pipe\033[0m");
		ft_printf("\n");
		tmp = tmp->next;
	}
}

void    ft_print_stt(t_lem *stt)
{
	ft_printf("\n\033[36;1mPRINT stt :\033[0m\n");
	print_ants(stt);
	print_start_end(stt);
	print_r(stt);
}
