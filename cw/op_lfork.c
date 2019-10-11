/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:02:45 by waddam            #+#    #+#             */
/*   Updated: 2019/10/11 20:27:36 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../corewar.h"

void	ft_init_lfork(t_op *op)
{
	op->arg_nbrs = 1;
	op->bef_op = 1000;
	op->need_arg_code = 0;
	op->t_dir = 2;

	op->code_args[0] = 128; //  DIR
	op->code_args[1] = '\0';
}

void op_lfork(t_cw *cw, t_crg *crg)
{
	int     i;
    t_args  args;
    t_crg   *new;

	i = 0;
    ft_bzero(&args, sizeof(args));
    args.pc_arg1 = (PC + OP_NAME) % MEM_SIZE;
    ft_DIR_2(cw, &args, 1);
	args.arg1 = (PC + args.arg1) % MEM_SIZE; // без усечения на % IDX_MOD
	if (args.arg1 < 0)
        args.arg1 = MEM_SIZE + (args.arg1 % MEM_SIZE);
	ft_add_carriage(cw, -(crg->reg[0]), args.arg1);
    new = cw->crg;
    while (i < REG_NUMBER)
    {
        new->reg[i] = crg->reg[i];
        i++;
    }
    new->carry = crg->carry;
    new->cur_op = crg->cur_op;
    new->bef_op = crg->bef_op;
    new->last_live = crg->last_live;
    new->step = crg->step; // нужно копировать
    PC = (PC + 3) % MEM_SIZE;
}
