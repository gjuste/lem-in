/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_connection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:44:23 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/02 14:48:32 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	delete_connection(t_room *r1, t_room *r2)
{
	t_links	*tmp;

	tmp = r1->links;
	while (tmp && tmp->r != r2)
		tmp = tmp->next;
	if (!tmp)
		return ;
	tmp->i = -1;
}

void		remove_connection(t_lem *stt, t_room *r1, t_room *r2)
{
	if (r1 == stt->start || r2 == stt->start)
		return ;
	delete_connection(r1, r2);
	delete_connection(r2, r1);
}
