/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 19:08:22 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/16 15:41:41 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_str		*join(t_str *str, t_str **lstr, char *line)
{
	t_str	*new;

	if (!(new = malloc(sizeof(t_str))))
		return (NULL);
	new->line = line;
	if (!str || !lstr)
	{
		(*lstr) = new;
		return (new);
	}
	(*lstr)->next = new;
	new->next = NULL;
	(*lstr) = (*lstr)->next;
	return (str);
}

void		deleter(t_str *str)
{
	if (str)
	{
		ft_strdel(&str->line);
		free(str);
		str = NULL;
	}
}

static void	get_opt(t_lem *stt, char **av)
{
	int		i;

	i = 0;
	av++;
	if (!ft_strcmp(*av, "-h"))
	{
		stt->opt = 0;
		return ;
	}
	while (*av)
	{
		if (*av[0] == '-')
		{
			if (ft_strcmp(*av, "-p") || ft_strcmp(*av, "--debug"))
				stt->opt = 2;
		}
		av++;
	}
}

static void	set_stt(t_lem *stt)
{
	stt->ants = 0;
	stt->p_ants = 0;
	stt->opt = 1;
	stt->min = 0;
	stt->p_nb = 0;
	stt->l_nb = 0;
	stt->l_need = 0;
	stt->sim = 0;
	stt->avp = 0;
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
	if (stt.opt >= 1)
	{
		if (parser(&stt) == -1)
			deleter(stt.str);
		if (set_resolve(&stt) == -1)
			ft_printf("ERROR\n");
		// ft_printf("LINE :\n%s", stt.str);
	}
	ft_print_stt(&stt);
	free_all(&stt);
	while(1);
	return (0);
}
