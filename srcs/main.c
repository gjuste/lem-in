/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 19:08:22 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/14 17:49:53 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	get_opt(t_lem *stt, char **av)
{
	int		i;

	i = 0;
	av++;
	while (*av)
	{
		if (*av[0] == '-')
		{
			if (ft_strstr(*av, "d") || ft_strstr(*av, "--debug"))
				stt->opt = 0;
		}
		av++;
	}
}

void	set_stt(t_lem *stt)
{
	stt->ants = 0;
	stt->opt = 1;
	stt->start = NULL;
	stt->end = NULL;
	stt->r = NULL;
}

int		main(int ac, char **av)
{
	t_lem	*stt;

	if (!(stt = (t_lem*)malloc(sizeof(t_lem))))
		ft_error(stt, 0);
	set_stt(stt);
	if (ac > 1)
		get_opt(stt, av);
	parser(stt);
	return (0);
}
