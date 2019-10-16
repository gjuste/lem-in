/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 19:08:22 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/17 00:01:58 by gjuste           ###   ########.fr       */
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
	if (!(new->line = ft_strdup(line)))
		i = -1;
	ft_strdel(&line);
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

void		deleter(t_str *str)
{
	t_str	*tmp;

	tmp = str;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp)
	{
		ft_strdel(&tmp->line);
		free(tmp);
		tmp = NULL;
	}
}

static void	get_opt(t_lem *stt, char **av)
{
	int		i;
	int		j;

	i = 0;
	av++;
	if (!ft_strcmp(*av, "-h"))
	{
		stt->opt = 0;
		return ;
	}
	while (av[i])
	{
		if (av[i][0] == '-')
		{
			if (!ft_strcmp(*av, "-p") || !ft_strcmp(*av, "--debug"))
				stt->opt = 2;
			if (ft_strcmp(*av, "-da") > 0 || ft_strcmp(*av, "--debug-ants") > 0)
			{
				j = 0;
				while (av[i][j] != '\0' && !ft_isdigit(av[i][j]))
					j++;
				stt->p_ants = ft_atoi(&av[i][j]);
			}
		}
		i++;
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
	}
	ft_print_stt(&stt);
	free_all(&stt);
	while(1); // A ENLEVER POUR PAS SE FAIRE ENCULER
	return (0);
}
