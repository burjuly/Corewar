/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 20:06:16 by waddam            #+#    #+#             */
/*   Updated: 2018/12/16 20:19:14 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int count, unsigned int temp)
{
	while (temp > 9)
	{
		temp = temp / 10;
		count++;
	}
	return (count);
}

static char	*ft_allocate(int count, unsigned int temp, char sign)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	str[count] = '\0';
	while (count > 0)
	{
		str[count - 1] = (temp % 10) + '0';
		temp = temp / 10;
		count--;
	}
	if (sign == '-')
		str[0] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	char			sign;
	int				count;
	unsigned int	temp;

	sign = '+';
	count = 1;
	temp = 0;
	if (n < 0)
	{
		temp = -n;
		sign = '-';
		count++;
	}
	else
		temp = n;
	count = ft_count(count, temp);
	return (ft_allocate(count, temp, sign));
}
