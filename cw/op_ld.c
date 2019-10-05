/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:21:04 by waddam            #+#    #+#             */
/*   Updated: 2019/10/05 23:32:41 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_ld(t_op *op)
{
	op->arg_nbrs = 2;
	op->ccl_cost = 5;
	op->need_arg_code = 1;
	op->low_tdir = 0;

	op->code_args[0] = DIR_REG;
	op->code_args[1] = IND_REG;
	op->code_args[2] = '\0';
}

int		ft_valid_code_arg(t_cw *cw, t_crg *crg, int code_op)
{
	int i;
	int pc;

	i = 0;
	pc = crg->pc + 1;
	printf("pc = %d\n", pc);
	printf("code 0 = %d\n", cw->op[1].code_args[0]);
	printf("code 1 = %d\n", cw->op[1].code_args[1]);
	while (cw->op[code_op].code_args[i])
	{
		printf("map[pc] = %d\n", cw->map[pc]);
		if (cw->map[pc] == (char)cw->op[code_op].code_args[i])
			return (cw->op[code_op].code_args[i]);
		i++;
	}
	return (-1);

}

// int		ft_skip_step(t_cw *cw, t_crg *crg, int code_op)
// {
	
// }

void	op_ld(t_cw *cw, t_crg *crg)
{
	int	code_arg;
	int pc_arg1;
	int	pc_arg2;
	int arg1;
	int arg2;
	char arg_char[4];


	arg1 = 0;
	arg2 = 0;
	pc_arg1 = 0;
	pc_arg2 = 0;
	code_arg = 0;
	code_arg = ft_valid_code_arg(cw, crg, 1);
	printf("ПОСЛЕ ВАЛИДАЦИИ АРГУМЕНТОВ code_arg = %d\n", code_arg );
	// if ((code_arg = ft_valid_code_arg(cw, crg, 1)) == -1)
	// {
	// 	//code_arg = ft_skip_step(cw, crg, 1);
	// 	return ;
	// }
	//ft_valid_reg();
	pc_arg1 = PC + NAME + CODE_ARGS;
	if (code_arg == DIR_REG) // DIR_SIZE = 4
	{
		printf("\n Зашли в IF!!!!!!! \n");
		pc_arg2 = pc_arg1 + DIR_4;
		
		printf("pc_arg1 = %d \n", pc_arg1);
		arg_char[3] = cw->map[pc_arg1];
		arg_char[2] = cw->map[pc_arg1 + 1];
		arg_char[1] = cw->map[pc_arg1 + 2];
		arg_char[0] = cw->map[pc_arg1 + 3];
		
		//arg1 = ft_byte_reverse_all(cw, pc_arg1, 4);
		//arg1 = ft_byte_reverse(&(cw->map[pc_arg1]), 4);
		arg1 = *(int*)arg_char;
		printf("arg1 = %d\n", arg1);
		arg2 = cw->map[pc_arg2];
	}
	else if (code_arg == IND_REG)
	{
		printf("\n Зашли в ELSE IF!!!!!!!  \n");
		pc_arg2 = pc_arg1 + IND;
		arg2 = cw->map[pc_arg2];
		arg1 = ft_byte_reverse_all(cw, pc_arg1, 2);
		pc_arg1 = PC + (arg1 % IDX_MOD);
		arg1 = ft_byte_reverse_all(cw, pc_arg1, 4);
	}
	crg->reg[arg2 - 1] = arg1;
	arg1 == 1 ? (crg->carry = 1) : (crg->carry = 0);
}


