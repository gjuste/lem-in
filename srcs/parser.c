/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:08:36 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/07 09:28:47 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

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
		return (-2);
	stt->ants = ft_atoi(line);
	return (i && stt->ants && !check_of(stt->ants, line, i) ? -1 : -2);
}

static void	get_nb_lines(t_lem *stt, char *line)
{
	int		i;

	i = 0;
	if (ft_strcmp(line, "#Here is the number of lines required:"))
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
	while (!i && (ret = get_next_line(0, &line)))
	{
		i++;
		if (!line)
			return (-1);
		ft_printf("%s\n", line);
		if (line[0] == '#' && line[1] != '#')
			i = 0;
		else
			i = set_nb_ants(stt, line);
		ft_strdel(&line);
	}
	if (ret <= 0 || i == -2 || stt->ants <= 0)
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
		if (!line)
			return (-1);
		ft_printf("%s\n", line);
		if (line[0] == '#')
		{
			if (line[1] == '#')
				i = check_cmd(stt, line);
			else
				get_nb_lines(stt, line);
		}
		if (line[0] != '#' && (i = room_fmt(stt, line) == -1))
			i = get_pipe(stt, line);
		ft_strdel(&line);
	}
	return (ret < 0 || !stt->r || !stt->start
		|| !stt->end || i == -2 ? -1 : 0);
}
