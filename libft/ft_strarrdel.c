/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:56:29 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/08/31 14:48:02 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strarrdel(char ***as)
{
	size_t	index;

	index = 0;
	if (as && *as)
	{
		while ((*as)[index])
			ft_strdel(&((*as)[index++]));
		free(*as);
		*as = NULL;
	}
}
