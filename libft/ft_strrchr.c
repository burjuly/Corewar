/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:10:24 by waddam            #+#    #+#             */
/*   Updated: 2018/12/09 14:03:22 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	size_t	len;

	temp = (char *)s;
	len = 0;
	while (*temp)
	{
		len++;
		temp++;
	}
	if (*temp == c)
		return (temp);
	temp--;
	while (len > 0)
	{
		if (c == *temp)
			return (temp);
		len--;
		temp--;
	}
	return (NULL);
}
