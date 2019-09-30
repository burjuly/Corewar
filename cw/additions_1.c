/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:59:05 by waddam            #+#    #+#             */
/*   Updated: 2019/10/01 00:28:28 by waddam           ###   ########.fr       */
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

void		ft_sort_plrs(t_plr *plr, int size)
{
	int		i;
	t_plr	temp;

	i = 0;
	while (i < size - 1)
	{
		if (plr[i].num > plr[i + 1].num)
		{
			temp = plr[i];
			plr[i] = plr[i + 1];
			plr[i + 1] = temp;
		}
		else if (plr[i].num == plr[i + 1].num)
		{
			if (plr[i + 1].flag_n == 1)
			{
				temp = plr[i];
				plr[i] = plr[i + 1];
				plr[i + 1] = temp;
				(plr[i + 1].num)++;
			}
		}
		i++;
	}
}
