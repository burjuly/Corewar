/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:18:37 by waddam            #+#    #+#             */
/*   Updated: 2018/12/21 05:43:43 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*temp;
	size_t	i;
	size_t	len;

	if (s && f)
	{
		len = ft_strlen(s);
		if (!(temp = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		i = 0;
		while (i < len)
		{
			temp[i] = f(s[i]);
			i++;
		}
		temp[i] = '\0';
		return (temp);
	}
	else
		return (NULL);
}
