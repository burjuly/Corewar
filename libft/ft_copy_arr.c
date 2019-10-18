/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:34:34 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/07/30 13:34:41 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_copy_arr(int number_of_str, char **str_arr)
{
	char				**ans;
	unsigned short int	i;

	i = 0;
	ans = (char **)malloc(sizeof(char *) * number_of_str + 1);
	if (!ans || !str_arr)
		return (NULL);
	while (str_arr[i])
	{
		ans[i] = ft_strdup(str_arr[i]);
		++i;
	}
	ans[i] = 0;
	return (ans);
}
