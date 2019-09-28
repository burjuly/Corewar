/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:39:01 by waddam            #+#    #+#             */
/*   Updated: 2018/12/21 04:14:44 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*temp_d;
	unsigned char	*temp_s;

	i = -1;
	temp_d = (unsigned char *)dst;
	temp_s = (unsigned char *)src;
	if (temp_d != temp_s)
	{
		if (temp_d <= temp_s)
		{
			while (++i < len)
				temp_d[i] = temp_s[i];
		}
		else
		{
			while (++i < len)
				temp_d[len - 1 - i] = temp_s[len - 1 - i];
		}
	}
	return (dst);
}
