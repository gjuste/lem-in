/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:10:56 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/15 23:02:53 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h" // supprimer ce commentaire seulement si le fichier est utile, sinon, supprimer le fichier whala

void	ft_error(t_lem *stt, int err)
{
	char	*l_err[5];

	l_err[0] = "ERROR";
	l_err[1] = "\033[31merror --\033[0m\tmalloc error";
	l_err[2] = "\033[31merror --\033[0m\tno number of ants";
	l_err[3] = "\033[31merror --\033[0m\twrong format";
	l_err[4] = "\033[31merror --\033[0m\tread error";
	l_err[4] = "\033[31merror --\033[0m\tpipe fornat error";
	if (stt->opt)
		err = 0 ;
	ft_printf("%s\n", l_err[err]);
	exit(1);
}
