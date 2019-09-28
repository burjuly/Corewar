/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 22:37:52 by waddam            #+#    #+#             */
/*   Updated: 2018/12/10 22:38:23 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_se_base(char const *s1, char const *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			continue ;
		}
		return (0);
	}
	if ((*s1 > *s2) || (*s1 < *s2))
		return (0);
	return (1);
}

int			ft_strequ(char const *s1, char const *s2)
{
	if (s1)
	{
		if (s2)
			return (ft_se_base(s1, s2));
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
