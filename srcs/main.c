/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 19:08:22 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/09 12:14:46 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

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
	stt->opt = 1;
	stt->min = 0;
	stt->p_nb = 0;
	stt->l_nb = 0;
	stt->l_need = 0;
	stt->p_size = NULL;
	stt->start = NULL;
	stt->end = NULL;
	stt->r = NULL;
}

int			main(int ac, char **av)
{
	t_lem	*stt;

	if (!(stt = (t_lem*)malloc(sizeof(t_lem))))
		ft_error(stt, 0);
	set_stt(stt);
	if (ac > 1)
		get_opt(stt, av);
	if (stt->opt >= 1)
	{
		if (parser(stt) == -1)
		{
			ft_printf("ERROR\n");
			return (0);
		}
		set_resolve(stt);
	}
	ft_print_stt(stt);
	free_all(stt);
	// while (1);
	return (0);
}
