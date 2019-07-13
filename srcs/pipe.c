/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 00:25:40 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/14 00:26:46 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		pipe_fmt(char *line)
{
	int		i;
	int		ret;

	if (!line || line[0] == 'L')
		return (0);
	i = 0;
	ret = 0;
	while (line[i] && line[i] != '-')
		i++;
	ret = i;
	while (line[i])
		i++;
	ret -= i;
	return (ret ? 1 : 0);
}

int		get_pipe(t_lem *stt, char *line)
{
	int		ret;

	stt->pipe = ft_strdup(line);
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (pipe_fmt(line))
			ft_printf("%s\n", line);
		if (line)
			ft_strdel(&line);
	}
	return (1);
}
