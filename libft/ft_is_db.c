/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_db.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:36:05 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/08/29 15:43:07 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_is_db(const char *str)
{
	int32_t		index;

	index = 0;
	while (str[++index])
		if (ft_is_blank(str[index - 1]) && ft_is_blank(str[index]))
			return (1);
	return (0);
}
