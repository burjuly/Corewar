/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:59:29 by waddam            #+#    #+#             */
/*   Updated: 2019/09/30 01:04:29 by waddam           ###   ########.fr       */
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
	cw->cclt_die = CYCLE_TO_DIE;
}

int		main(int argc, char **argv)
{
	t_cw	cw;

	ft_parse(argc, argv, &cw);
	ft_game(&cw);
	return (0);
}
