/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:20:24 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/15 15:38:13 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_complet_path(t_lem *stt, t_room *room)
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

void	print_path(t_lem *stt)
{
	t_links *lnk;

	ft_printf("\n");
	lnk = stt->start->links;
	while (lnk)
	{
		if (lnk->i == 1)
		{
			ft_printf("nb rooms chemin : %s%d%s\n", C, lnk->r->nb_r, RS);
			ft_printf("%s%s%s || ", BW, stt->start->name, RS);
			get_complet_path(stt, lnk->r);
			ft_printf("\n");
		}
		lnk = lnk->next;
	}
}

void	print_stt(t_lem *stt)
{
	int		i;

	i = 0;
	ft_printf("\n");
	ft_printf("ants : %s%d%s\n", G, stt->ants, RS);
	ft_printf("opt : %s%d%s\n", G, stt->opt, RS);
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

void	print_r(t_lem *stt)
{
	t_room	*tmp;
	t_links	*l;

	ft_printf("\n");
	tmp = stt->r;
	while (tmp)
	{
		l = tmp->links;
		ft_printf("room : %s%-7s%s |  ", P, tmp->name, RS);
		ft_printf("%s%3d%s / %s%3d%s || ", C, tmp->x, RS, B, tmp->y, RS);
		ft_printf("marque : %s%2d%s  | ", G, tmp->marque, RS);
		ft_printf("done : %s%2d%s  || ", G, tmp->done, RS);
		ft_printf("ants : %s%5d%s  || ", G, tmp->ants, RS);
		while (l)
		{
			if (l->i == 1)
				ft_printf("  %s%s%s", P, l->r->name, RS);
			else
				ft_printf("  %s%s%s", Y, l->r->name, RS);
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
	ft_printf("   -h (--help)\t     --> guide options\n");
	ft_printf("   -v (--verbose)    --> return error find\n");
	ft_printf("   -l (--line)\t     --> count of line to resolve\n");
	ft_printf("   -p (--print-all)  --> print all\n");
	ft_printf("       -ps (--print_struct)  --> print structure\n");
	ft_printf("       -pp (--print_path)    --> print path\n");
	ft_printf("       -pr (--print_room)    --> print room infos\n");
	ft_printf("   -db (--debug-bfs)\t\t --> print BFS path find\n"); // a voir si pas trop chiant a faire
	ft_printf("   -da[1-9] (--debug-ants[1-9])  --> print in red moves of an ants\n");
}

void		print_line(t_lem *stt)
{
	if (!stt->l_nb)
		return ;
	ft_printf("\nnombre de lignes affichées : ");
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
		ft_printf("nombre de lignes attendues : ");
		ft_printf("%s%d%s\n", BW, stt->l_need, RS);
	}
}

void		ft_print_stt(t_lem *stt)
{
	if (stt->opt == 0)
	{
		print_help();
		return ;
	}
	print_line(stt);
	ft_printf("\n%sINFOS PRINT :%s\n", BC, RS);
	print_stt(stt);
//	print_r(stt);
	// print_path(stt);
}
