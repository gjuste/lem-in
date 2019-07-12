/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:08:36 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/13 01:54:13 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	get_nb_ants(t_lem *stt)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = get_next_line(0, &line);
	if (line)
	{
		stt->ants = ft_atoi(line);
		ft_strdel(&line);
	}
	if (stt->ants <= 0)
		ret = -2;
	if (ret <= 0)
		ft_error(stt, ret < 0 ? 2 : 3);
}

static int	check_format(char *line)
{
	int		i;
	int		ret;

	if (line[0] == 'L')
		return (0);
	i = 0;
	ret = 0;
	while (line[i] && line[i] != ' ')
		i++;
	i++;
	while (line[i] && ft_isdigit(line[i]))
	{
		ret++;
		i++;
	}
	if (!line[i] || line[i] != ' ' || ret == 0)
		return(0);
	i++;
	ret = 0;
	while (line[i] && ft_isdigit(line[i]))
	{
		ret++;
		i++;
	}
	return (ret ? 1 : 0);
}

static char	*get_cmd(t_lem *stt, char *l_tmp)
{
	int		i;
	int		ret;
	char	*name;

	name = NULL;
	if ((ret = check_format(l_tmp)))
	{
		i = 0;
		while (l_tmp[i] != ' ')
			i++;
		name = ft_strndup(l_tmp, i);
	}
	if (ret == 0 || !name)
	{
		ft_strdel(&l_tmp);
		ft_error(stt, !name ? 1 : 3);
	}
	return (name);
}

static void	check_cmd(t_lem *stt, char *line)
{
	char	**cmd;
	char	*l_tmp;
	int		ret;
	int		check;

	if (ft_strstr(line, "##start"))
		cmd = &(stt->start);
	else if (ft_strstr(line, "##end"))
		cmd = &(stt->end);
	else
		return;
	check = 0;
	while ((ret = get_next_line(0, &l_tmp)) > 0 && !check)
	{
		if (l_tmp && l_tmp[0] != '#')
		{
			*cmd = get_cmd(stt, l_tmp);
			check++;
		}
		ft_strdel(&l_tmp);
	}
	ft_printf("\033[32m%s %s\033[0m\n", stt->start, stt->end);
	if (ret == -1)
		ft_error(stt, 4);
}

int			parser(t_lem *stt)
{
	char	*line;
	int		ret;

	get_nb_ants(stt);
	line = NULL;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (line[0] == '#' && line[1] == '#')
			check_cmd(stt, line);
		if (line[0] != '#' && !check_format(line))
			ft_error(stt, 3);
		ft_strdel(&line);
	}
	return (ret < 0 ? 0 : 1);
}
