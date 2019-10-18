/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:43:03 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/08/29 15:39:01 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t			ft_atoi(const char *str)
{
	size_t		index;
	int32_t		sign;
	uint32_t	number;

	number = 0;
	index = 0;
	while (str[index] && (ft_is_blank(str[index]) || str[index] == '\v' ||
			str[index] == '\f' || str[index] == '\r'))
		++index;
	sign = ((str[index] == '-') ? -1 : 1);
	if (str[index] == '-' || str[index] == '+')
		++index;
	while (ft_isdigit(str[index]))
		number = number * 10 + (str[index++] - '0');
	return ((int32_t)number * sign);
}
