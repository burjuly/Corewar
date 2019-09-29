/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:59:05 by waddam            #+#    #+#             */
/*   Updated: 2019/09/30 01:04:50 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static void	ft_swap_char(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void		ft_byte_reverse(char *bytes_array)
{
	ft_swap_char(&bytes_array[0], &bytes_array[3]);
	ft_swap_char(&bytes_array[1], &bytes_array[2]);
}

int			ft_check_repeat(int *array, size_t size)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < size)
	{
		temp = array[i];
		j = 0;
		while (j < size)
		{
			if (temp == array[j] && j != i)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
