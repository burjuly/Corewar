/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_m.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 21:30:16 by waddam            #+#    #+#             */
/*   Updated: 2019/01/25 20:27:23 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc_m(size_t size)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	if (!(temp = (unsigned char *)malloc(size)))
		return (NULL);
	while (i < size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}
