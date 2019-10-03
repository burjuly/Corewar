/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:59:29 by waddam            #+#    #+#             */
/*   Updated: 2019/10/04 00:22:17 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_leave(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}

void	ft_initialize(t_cw *cw)
{
	ft_bzero(cw, sizeof(t_cw));
	cw->c_to_die = CYCLE_TO_DIE;
}

int		main(int argc, char **argv)
{
	t_cw	cw;

	ft_parse(argc, argv, &cw);

	/******************************************/
	// Проверка что правильно расставляются num
	int i = 0;
    printf("кол-во игроков %d\n", cw.plr_nbrs);
    while (i < cw.plr_nbrs)
    {
        printf("plr %d его num = %d\n", i, cw.plr[i].num);
        i++;
    }
	/*******************************************/

	// ft_game(&cw);
	return (0);
}
