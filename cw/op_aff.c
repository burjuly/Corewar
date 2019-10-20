/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:06:18 by waddam            #+#    #+#             */
/*   Updated: 2019/10/21 00:49:07 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_aff(t_op *op)
{
	op->arg_nbrs = 1;
	op->bef_op = 2;
	op->need_arg_code = 1;
	op->t_dir = 4;
	op->code_args[0] = 64;
	op->code_args[1] = '\0';
}

void	op_aff(t_cw *cw, t_crg *crg)
{
	t_args	args;

	ft_bzero(&args, sizeof(args));
	args.pc_arg1 = (crg->pc + OP_NAME + CODE_ARGS) % MEM_SIZE;
	ft_reg(cw, crg, &args, 1);
	ft_printf("Aff: %c\n", (char)(args.arg1 % 256));
}
