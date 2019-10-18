/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:35:45 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/07/30 13:35:47 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_lstfold(int x, int *arr, int (*f)(int, int), int lenarr)
{
	int			i;
	long long	ans;

	if (arr && f)
	{
		i = 0;
		ans = x;
		while (i < lenarr)
			ans = f(ans, arr[i++]);
		return (ans);
	}
	return ((long long)x);
}
