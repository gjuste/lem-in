/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:20:24 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/17 13:23:22 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_stt(t_lem *stt)
{
	int		i;

	i = 0;
	ft_printf("\n%sStrucutre data :%s\n", BW, RS);
	ft_printf("ants : %s%d%s\n", G, stt->ants, RS);
	ft_printf("sim : %s%d%s\n", G, stt->sim, RS);
	if (stt->p_size)
	{
		ft_printf("min : %s%d%s || ", G, stt->min, RS);
		ft_printf("p_nb : %s%d%s\np_size : ", G, stt->p_nb, RS);
		while (i < stt->p_nb - 1)
			ft_printf("%s%d%s | ", G, stt->p_size[i++]->nb_r, RS);
		ft_printf("%s%d%s\n", G, stt->p_size[i]->nb_r, RS);
	}
	if (stt->start)
		ft_printf("start : %s%s%s  ||  ", G, stt->start->name, RS);
	else
		ft_printf("%sno start%s  ||  ", R, RS);
	if (stt->end)
		ft_printf("end : %s%s%s\n", G, stt->end->name, RS);
	else
		ft_printf("%sno end%s\n", R, RS);
}

void		print_r(t_lem *stt)
{
	t_room	*tmp;
	t_links	*l;

	ft_printf("\n%sRooms data :%s\n", BW, RS);
	tmp = stt->r;
	while (tmp)
	{
		l = tmp->links;
		ft_printf("room : %s%-7s%s |  ", P, tmp->name, RS);
		ft_printf("%s%3d%s / %s%3d%s || ", C, tmp->x, RS, B, tmp->y, RS);
		ft_printf("nb_r : %s%2d%s  | ", G, tmp->nb_r, RS);
		ft_printf("done : %s%2d%s  || ", G, tmp->done, RS);
		ft_printf("ants : %s%5d%s  || ", G, tmp->ants, RS);
		while (l)
		{
			ft_printf("  %s%s%s", l->i == 1 ? P : Y, l->r->name, RS);
			l = l->next;
		}
		if (!tmp->links)
			ft_printf("  %sno pipe%s", R, RS);
		ft_printf("\n");
		tmp = tmp->next;
	}
}

void		print_help(void)
{
	ft_printf("usage : ./lem-in [opt] < 'file path'\noptions :\n");
	ft_printf("   -h (--help)  --> guide options\n");
	ft_printf("   -l (--line)  --> count of line to resolve\n");
	ft_printf("   -p (--print) --> print all following informations\n");
	ft_printf("       -ps      --> print structure\n");
	ft_printf("       -pp      --> print path\n");
	ft_printf("       -pr      --> print room infos\n");
	ft_printf("   -da[1-9]  --> print in red moves of an ants\n");
}

void		print_line(t_lem *stt)
{
	if (!stt->l_nb)
		return ;
	ft_printf("\n%sLines :%s\n", BW, RS);
	ft_printf("number of lines done : ");
	if (!stt->l_need)
		ft_printf("%s%d%s\n", BW, stt->l_nb, RS);
	else if (stt->l_nb <= stt->l_need)
		ft_printf("%s%d%s\n", BG, stt->l_nb, RS);
	else if (stt->l_nb <= stt->l_need + 5)
		ft_printf("%s%d%s\n", BY, stt->l_nb, RS);
	else
		ft_printf("%s%d%s\n", BR, stt->l_nb, RS);
	if (stt->l_need)
	{
		ft_printf("number of lines expected : ");
		ft_printf("%s%d%s\n", BW, stt->l_need, RS);
	}
}

void		ft_print_stt(t_lem *stt)
{
	if (stt->opt & LI)
		print_line(stt);
	if (stt->opt & PA || stt->opt & PS)
		print_stt(stt);
	if (stt->opt & PA || stt->opt & PR)
		print_r(stt);
	if (stt->opt & PA || stt->opt & PP)
		print_path(stt);
}
