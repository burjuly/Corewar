/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:08:27 by waddam            #+#    #+#             */
/*   Updated: 2018/12/09 19:19:23 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_d;
	size_t	len_s;

	i = ft_strlen(dst);
	j = -1;
	len_d = i;
	len_s = ft_strlen(src);
	if (size == 0)
		return (len_s);
	if (size > (len_s + len_d + 1))
		ft_strcat(dst, src);
	else
	{
		while (i < size - 1)
		{
			dst[i] = src[++j];
			i++;
		}
		dst[i] = '\0';
	}
	if (i >= size)
		len_d = size;
	return (len_s + len_d);
}
