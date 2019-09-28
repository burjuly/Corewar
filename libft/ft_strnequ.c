/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 23:18:03 by waddam            #+#    #+#             */
/*   Updated: 2018/12/10 23:18:05 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sne_base(char const *s1, char const *s2, size_t n)
{
	while (*s1 && *s2)
	{
		if ((*s1 == *s2) && (n > 1))
		{
			s1++;
			s2++;
			n--;
			continue ;
		}
		if (n != 1)
			return (0);
		else
			break ;
	}
	if ((*s1 > *s2) || (*s1 < *s2))
		return (0);
	return (1);
}

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (n == 0)
		return (1);
	else
	{
		if (s1)
		{
			if (s2)
				return (ft_sne_base(s1, s2, n));
			else
				return (0);
		}
		else
		{
			if (s2)
				return (0);
			else
				return (1);
		}
	}
}
