/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 02:33:20 by waddam            #+#    #+#             */
/*   Updated: 2018/12/18 03:01:45 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	temp = NULL;
	if (alst && del)
	{
		temp = *alst;
		del(temp->content, temp->content_size);
		temp->next = NULL;
		free(temp);
		*alst = NULL;
	}
}
