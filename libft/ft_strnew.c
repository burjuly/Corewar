/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:52:19 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/01/04 14:32:47 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ans;
	size_t	i;

	i = -1;
	ans = ft_memalloc(size + 1);
	if (ans)
	{
		while (i++ < size)
			ans[i] = '\0';
		return (ans);
	}
	return (NULL);
}
