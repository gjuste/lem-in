/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:46:26 by jpelleti          #+#    #+#             */
/*   Updated: 2018/11/16 09:32:38 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;
	void	*content2;
	size_t	size;

	if (!(lst = malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		content2 = ft_memalloc(content_size);
		size = content_size;
		ft_memcpy(content2, content, size);
		lst->next = NULL;
		lst->content = content2;
		lst->content_size = size;
	}
	if (!content)
	{
		lst->content = NULL;
		lst->content_size = 0;
		lst->next = NULL;
	}
	return (lst);
}
