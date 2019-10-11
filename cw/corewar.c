/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:59:29 by waddam            #+#    #+#             */
/*   Updated: 2019/10/11 16:57:24 by draudrau         ###   ########.fr       */
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
	ft_init_live(cw->op + 0);
	ft_init_ld(cw->op + 1);
	ft_init_st(cw->op + 2);
	ft_init_add(cw->op + 3);
	ft_init_sub(cw->op + 4);
	ft_init_and(cw->op + 5);
	ft_init_or(cw->op + 6);
	ft_init_xor(cw->op + 7);
	ft_init_zjmp(cw->op + 8);
	ft_init_ldi(cw->op + 9);
	ft_init_sti(cw->op + 10);
	ft_init_fork(cw->op + 11);
	ft_init_lld(cw->op + 12);
	ft_init_lldi(cw->op + 13);
	ft_init_lfork(cw->op + 14);
	ft_init_aff(cw->op + 15);
	cw->cycle_to_die = CYCLE_TO_DIE;
}

int		main(int argc, char **argv)
{
	t_cw	cw;

	ft_parse(argc, argv, &cw);
	ft_map(&cw);
	ft_start_game(&cw);
	return (0);
}
