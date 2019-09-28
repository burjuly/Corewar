/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:39:39 by waddam            #+#    #+#             */
/*   Updated: 2018/12/09 19:32:18 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*hst;
	char	*ndl;
	size_t	i;
	size_t	j;

	hst = (char *)haystack;
	ndl = (char *)needle;
	i = 0;
	if (ndl[0] == '\0')
		return (hst);
	while (hst[i] != '\0')
	{
		j = 0;
		if (hst[i] == ndl[j])
		{
			while ((hst[i + j] == ndl[j]) && ndl[j] != '\0')
				j++;
			if (ndl[j] == '\0')
				return (&hst[i]);
		}
		i++;
	}
	return (NULL);
}
