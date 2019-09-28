/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 00:04:41 by waddam            #+#    #+#             */
/*   Updated: 2018/12/19 15:05:24 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ts1;
	unsigned char	*ts2;
	size_t			i;

	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	if (n > ft_strlen((char *)ts1))
		return (ft_strcmp((char *)ts1, (char *)ts2));
	else
		while (ts1[i] == ts2[i] && i < (n - 1))
			i++;
	return (ts1[i] - ts2[i]);
}
