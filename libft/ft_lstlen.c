/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:36:18 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/08/29 15:50:59 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *begin)
{
	int		len;

	if (!begin)
		return (0);
	len = 0;
	while (begin)
	{
		begin = begin->next;
		++len;
	}
	return (len);
}
