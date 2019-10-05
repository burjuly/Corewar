/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:21:04 by waddam            #+#    #+#             */
/*   Updated: 2019/10/05 15:29:58 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_ld(t_op *op)
{
	ft_init_arg1(op);
	ft_init_arg2(op);
	op->arg_nbrs = 2;
	op->ccl_cost = 5;
	op->need_arg_code = 1;
	op->low_tdir = 0;
}

int		ft_valid_arg_ld(int pc)
{

}

void	ft_ld(t_cw *cw, t_crg *crg)
{
	int arg_1;
	int arg_2;

	//if (ft_valid_arg_ld(crg->pc + 1) == 0)
	//
	//
	if (arg_1 == 2) // первый аргумент T_DIR
	{

	}
}
