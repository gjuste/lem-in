/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:08:36 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/25 16:41:37 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_of(int nb, char *line, int i)
{
	int		j;
	char	c;

	j = i - 1;
	while (j >= 0)
	{
		c = (nb % 10 + '0');
		if (line[j] != c)
			return (-1);
		nb = nb / 10;
		j--;
	}
	return (0);
}

static int	set_nb_ants(t_lem *stt, char *line)
{
	int		i;

	i = 0;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i] || !i)
		return (-1);
	stt->ants = ft_atoi(line);
	return (i && stt->ants && !check_of(stt->ants, line, i) ? 1 : -1);
}

static void	get_nb_lines(t_lem *stt, char *line)
{
	int		i;

	i = 0;
	if (ft_strstr(line, "#Here is the number of lines required:"))
	{
		i = 0;
		while (!ft_isdigit(line[i]))
			i++;
		stt->l_need = ft_atoi(&line[i]);
		if (stt->l_need < 0)
			stt->l_need = 0;
	}
}

static int	get_nb_ants(t_lem *stt)
{
	char	*line;
	int		ret;
	int		i;

	line = NULL;
	i = 0;
	while (!i && (ret = get_next_line(0, &line) > 0))
	{
		i++;
		if (line[0] == '#' && ft_strcmp(line, "##start")
			&& ft_strcmp(line, "##end"))
			i = 0;
		else
			i = set_nb_ants(stt, line);
		if (!(join(stt, &stt->lstr, line)))
			i = -1;
	}
	if (ret <= 0 || i == -1 || stt->ants <= 0)
		return (-1);
	return (0);
}

int			parser(t_lem *stt)
{
	char	*line;
	int		ret;
	int		i;

	i = get_nb_ants(stt);
	line = NULL;
	while (!i && (ret = get_next_line(0, &line)) > 0)
	{
		if (!(join(stt, &stt->lstr, line)))
			return (-1);
		if (line[0] == '#')
		{
			if (line[1] == '#')
				i = check_cmd(stt, line);
			else
				get_nb_lines(stt, line);
		}
		if (!i && line[0] != '#' && (i = room_fmt(stt, line) == -1))
			i = get_pipe(stt, line);
	}
	return (ret < 0 || !stt->r || i < 0 ? -1 : 0);
}
