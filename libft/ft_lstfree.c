/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:36:02 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/08/30 13:39:35 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfree(t_list *begin)
{
	t_list		*tmp;

	if (!begin)
		return (NULL);
	while (begin)
	{
		free(begin->content);
		begin->content_size = 0;
		tmp = begin;
		begin = begin->next;
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}
