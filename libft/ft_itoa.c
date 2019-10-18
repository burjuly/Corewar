/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 12:38:06 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/09/01 14:32:37 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa(int number)
{
	char	*str;
	int		numlen;
	int		sign;
	int		digit;

	sign = (number < 0) ? 1 : 0;
	if (number == -2147483648)
		return (ft_strdup("-2147483648"));
	number = (number < 0) ? -number : number;
	numlen = ft_int_size(number) + (sign ? 1 : 0);
	if ((str = ft_strnew(numlen)))
	{
		str[numlen--] = '\0';
		while (numlen >= sign)
		{
			digit = number % 10;
			str[numlen--] = digit + '0';
			number /= 10;
		}
		if (sign)
			str[0] = '-';
	}
	return (str);
}
