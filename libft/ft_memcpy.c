/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:13:26 by waddam            #+#    #+#             */
/*   Updated: 2018/12/21 03:58:09 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_d;
	unsigned char	*temp_s;

	i = 0;
	temp_d = (unsigned char *)dst;
	temp_s = (unsigned char *)src;
	if (temp_d != temp_s)
	{
		while (i < n)
		{
			temp_d[i] = temp_s[i];
			i++;
		}
	}
	return (dst);
}
