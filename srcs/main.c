/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 19:08:22 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/17 14:00:56 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*join(t_lem *stt, t_str **lstr, char *line)
{
	t_str	*new;
	int		i;

	i = 0;
	if (!(new = (t_str*)malloc(sizeof(t_str))))
		return (NULL);
	new->line = line;
	new->next = NULL;
	if (!stt->str || !lstr)
	{
		stt->str = new;
		(*lstr) = new;
		return (!i ? new->line : NULL);
	}
	(*lstr)->next = new;
	(*lstr) = (*lstr)->next;
	return (!i ? new->line : NULL);
}

static void	get_opt(t_lem *stt, char **av)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (!ft_strcmp(av[i], "-h") || !ft_strcmp(av[i], "--help"))
			stt->opt = stt->opt | HE;
		if (!ft_strcmp(av[i], "-l") || !ft_strcmp(av[i], "--line"))
			stt->opt = stt->opt | LI;
		if (!ft_strcmp(av[i], "-p") || !ft_strcmp(av[i], "--print"))
			stt->opt = stt->opt | PA;
		if (!ft_strcmp(av[i], "-ps"))
			stt->opt = stt->opt | PS;
		if (!ft_strcmp(av[i], "-pp"))
			stt->opt = stt->opt | PP;
		if (!ft_strcmp(av[i], "-pr"))
			stt->opt = stt->opt | PR;
		if (ft_strcmp(av[i], "-da") > 0)
			stt->p_ants = ft_atoi(&av[i][3]);
		i++;
	}
}

static void	set_stt(t_lem *stt)
{
	stt->ants = 0;
	stt->p_ants = 0;
	stt->opt = 0;
	stt->min = 0;
	stt->p_nb = 0;
	stt->l_nb = 0;
	stt->l_need = 0;
	stt->sim = 0;
	stt->avp = 0;
	stt->errstr = 0;
	stt->str = NULL;
	stt->lstr = NULL;
	stt->p_size = NULL;
	stt->start = NULL;
	stt->end = NULL;
	stt->r = NULL;
}

int			main(int ac, char **av)
{
	t_lem	stt;

	set_stt(&stt);
	if (ac > 1)
		get_opt(&stt, av);
	if (stt.opt & HE)
	{
		print_help();
		return (0);
	}
	if (parser(&stt) == -1)
		stt.errstr = 1;
	if (set_resolve(&stt) == -1)
		ft_printf("ERROR\n");
	ft_print_stt(&stt);
	free_all(&stt);
	return (0);
}
