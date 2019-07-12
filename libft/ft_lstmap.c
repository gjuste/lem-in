/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:24:51 by jpelleti          #+#    #+#             */
/*   Updated: 2018/11/15 15:32:06 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *ptr;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	ptr = new;
	while (lst)
	{
		new->next = (*f)(lst);
		new = new->next;
		lst = lst->next;
	}
	return (ptr->next);
}
