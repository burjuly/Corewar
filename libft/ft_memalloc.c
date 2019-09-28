/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 21:30:16 by waddam            #+#    #+#             */
/*   Updated: 2018/12/21 06:21:44 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	if (!(temp = (unsigned char *)malloc(size)) || size == 0)
		return (NULL);
	while (i < size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}
