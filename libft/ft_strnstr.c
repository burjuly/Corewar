/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:29:09 by waddam            #+#    #+#             */
/*   Updated: 2018/12/19 15:03:29 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*hst;
	char	*ndl;
	size_t	i;
	size_t	j;

	hst = (char *)s1;
	ndl = (char *)s2;
	i = 0;
	if (ndl[0] == '\0')
		return (hst);
	while (hst[i] != '\0' && i < len)
	{
		j = 0;
		if (hst[i] == ndl[j])
		{
			while ((hst[i + j] == ndl[j]) && (ndl[j] != '\0') && i + j < len)
				j++;
			if (ndl[j] == '\0')
				return (&hst[i]);
		}
		i++;
	}
	return (NULL);
}
