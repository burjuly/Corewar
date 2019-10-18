/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:37:27 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/08/29 15:58:17 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t		i;
	size_t		j;
	char		tmp;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		++i;
	if (i == 0)
		return (str);
	--i;
	j = 0;
	while (j < i)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		++j;
		--i;
	}
	return (str);
}
