/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:56:36 by waddam            #+#    #+#             */
/*   Updated: 2019/10/08 16:45:40 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../corewar.h"

void	ft_init_fork(t_op *op)
{
	op->arg_nbrs = 1;
	op->bef_op = 800;
	op->need_arg_code = 0;
	op->t_dir = 2;

    op->code_args[0] = 128; //  DIR
	op->code_args[1] = '\0';
}

// int		ft_byte_reverse_all(t_cw *cw, int pc, int count)
// {
//     int     i;
//     int     num;
//     char    two_bytes[2];
//     char    four_bytes[4];

//     i = 0;
//     if (count == 2) // 2 байта
//     {
//         while (i < count)
//         {
//             two_bytes[i] = cw->map[pc + i];
//             i++;
//         }
//         num = ft_byte_reverse(two_bytes, 2);
//     }
//     else // 4 байта
//     {
//         while (i < count)
//         {
//             four_bytes[i] = cw->map[pc + i];
//             i++;
//         }
//         num = ft_byte_reverse(two_bytes, 4);
//     }
//     return (num);
// }

void op_fork(t_cw *cw, t_crg *crg)
{
    int     i;
    t_args  args;
    t_crg   *new;

	i = 0;
    ft_bzero(&args, sizeof(args));
    args.pc_arg1 = (PC + OP_NAME) % MEM_SIZE;
    ft_DIR_2(cw, &args, 1);
    args.arg1 = (PC + args.arg1 % IDX_MOD) % MEM_SIZE;
    if (args.arg1 < 0)
         args.arg1 = args.arg1 + (args.arg1 % MEM_SIZE);
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
    new->step = crg->step;
    PC = (PC + 3) % MEM_SIZE;
}
