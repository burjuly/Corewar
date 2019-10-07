/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:11:48 by draudrau          #+#    #+#             */
/*   Updated: 2019/10/07 13:39:41 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		ft_MOD_IND(int arg)
{
	arg = arg % MEM_SIZE;
	if (arg < 0)
		arg = arg + MEM_SIZE;
	return (arg);
}

// int		ft_valid_REG(t_cw *cw, t_crg *crg)
// {
	

// }

void	ft_wrong_code_args(t_crg *crg, int size_DIR, char code)
{
	int		step;	

	step = 0;
	// проверяем 1 и 2 бит - 11 00 00 00
	if ((code & 0xC0) >> 6 == 0x1) // 00 00 00 01 	REG = 1
		step = step + 1;
	else if ((code & 0xC0) >> 6 == 0x2) // 00 00 00 10 DIR = size_DIR
		step = step + size_DIR;
	else if ((code & 0xC0) >> 6 == 0x3) // 00 00 00 11 IND = 2
		step = step + 2;

	// проверяем 3 и 4 бит - 00 11 00 00
	if ((code & 0x30) >> 4 == 0x1)
		step = step + 1;
	else if ((code  & 0x30) >> 4 == 0x2)
		step = step + size_DIR;
	else if ((code  & 0x30) >> 4 == 0x3)
		step = step + 2;

	// проверяем 5 и 6 бит - 00 00 11 00
	if ((code & 0xC) >> 2 == 0x1)
		step = step + 1;
	else if ((code & 0xC) >> 2 == 0x2)
		step = step + size_DIR;
	else if ((code & 0xC) >> 2 == 0x3)
		step = step + 2;
	crg->step = OP_NAME + CODE_ARGS + step;
}

int		ft_valid_code_arg(t_cw *cw, t_crg *crg, int code_op)
{
	int     i;
	int     pc;
    char	code_arg;

	i = 0;
	pc = (PC + 1) % MEM_SIZE;
	code_arg = cw->map[pc];
	while (cw->op[code_op].code_args[i])
	{
		if (code_arg == (char)cw->op[code_op].code_args[i])
			return (cw->op[code_op].code_args[i]); // ВСЕ ОК
		i++;
	}
	ft_wrong_code_args(crg, cw->op[code_op].t_dir, code_arg); // НЕВЕРНЫЙ КОД АРГУМЕНТОВ
	return (-1);
}