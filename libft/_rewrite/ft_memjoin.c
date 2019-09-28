/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 07:51:22 by waddam            #+#    #+#             */
/*   Updated: 2019/01/22 07:51:40 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memjoin(void *s1, void *s2, size_t size1, size_t size2)
{
	unsigned char	*temp;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;
	size_t			i;
	size_t			j;

	temp = NULL;
	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	i = -1;
	j = -1;
	if (temp_s1 || temp_s2)
	{
		size1 = (temp_s1 ? size1 : 0);
		size2 = (temp_s2 ? size2 : 0);
		if (!(temp = ft_memalloc(size1 + size2)))
			return (NULL);
		while (++i < size1)
			temp[i] = temp_s1[i];
		while (++j < size2)
			temp[i + j] = temp_s2[j];
	}
	return (temp);
}
