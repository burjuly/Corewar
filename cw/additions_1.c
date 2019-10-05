/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:59:05 by waddam            #+#    #+#             */
/*   Updated: 2019/10/06 00:28:25 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

/*
** TODO
** Перенести сортировку в players2.c
** Сделать функции для сортировки с флагом и без, вызывать их из ft_correct_plrs
** void swap?
*/

static void	ft_swap_char(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int			ft_byte_reverse(char *bytes_array, int count)
{
	if (count == 2)
		ft_swap_char(&bytes_array[0], &bytes_array[1]);
	else if (count == 4)
	{
		ft_swap_char(&bytes_array[0], &bytes_array[3]);
		ft_swap_char(&bytes_array[1], &bytes_array[2]);
	}
	return (*(int *)bytes_array);
}

static void	ft_swap_plrs(t_plr *a, t_plr *b)
{
	t_plr	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	ft_no_flag_sort_plrs(t_plr *plr, int size)
{
	int		i;
	int		j;
	int		min;

	i = 0;
	while (i < size)
	{
		if (plr[i].flag_n != 1)
		{
			min = plr[i].num;
			j = 0;
			while (j < size)
			{
				if (plr[j].flag_n != 1 && plr[j].num < min && i < j)
				{
					min = plr[j].num;
					ft_swap_plrs(&plr[i], &plr[j]);
				}
				j++;
			}
		}
		i++;
	}
}

void		ft_sort_plrs(t_plr *plr, int size)
{
	int		i;
	int		pos;

	i = 0;
	while (i < size)
	{
		pos = plr[i].num - 1;
		if (plr[i].flag_n == 1 && i != pos)
			ft_swap_plrs(&plr[i], &plr[pos]);
		i++;
	}
	ft_no_flag_sort_plrs(plr, size);
	i = 0;
	while (i < size)
	{
		plr[i].num = i + 1;
		i++;
	}
}
