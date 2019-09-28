/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 21:42:57 by waddam            #+#    #+#             */
/*   Updated: 2018/12/19 00:04:01 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = NULL;
	temp2 = NULL;
	if (alst && del)
	{
		temp1 = *alst;
		while (temp1)
		{
			temp2 = temp1->next;
			del(temp1->content, temp1->content_size);
			free(temp1);
			temp1 = temp2;
		}
		*alst = NULL;
	}
}
