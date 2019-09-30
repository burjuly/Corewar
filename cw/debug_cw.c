/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_cw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 00:32:25 by waddam            #+#    #+#             */
/*   Updated: 2019/10/01 01:09:59 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_print_plrs(t_plr *plr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		printf(">>Player%i<<\n", i + 1);
		printf("num:       %i\n", plr[i].num);
		printf("name:      %s\n", plr[i].name);
		printf("code_size: %i\n", plr[i].code_size);
		printf("comment:   %s\n", plr[i].comment);
		printf("code:      %s\n", plr[i].code);
		printf("flag_n:    %i\n", plr[i].flag_n);
		i++;
		if (i != size)
			printf("\n");
	}
}
