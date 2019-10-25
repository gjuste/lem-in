/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:46:07 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/16 22:14:03 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		do_simulation(t_lem *stt, t_queue *q, t_links *lnk)
{
	if ((stt->p_nb == 0 && stt->avp == 0) ||
		(stt->p_nb > 0 && stt->avp > 0 && stt->p_nb < stt->ants && (stt->avp
		+ stt->ants + q->r->marque + 1) / (stt->p_nb + 1) <= stt->sim))
	{
		stt->sim = (stt->avp + stt->ants + q->r->marque + 1) / (stt->p_nb + 1);
		lnk->r->parent = q->r;
		stt->avp -= lnk->r->marque;
		lnk->r->marque = q->r->marque + 1;
		stt->avp += lnk->r->marque - 1;
	}
	return (0);
}
