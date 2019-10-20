/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:11:48 by draudrau          #+#    #+#             */
/*   Updated: 2019/10/20 20:49:34 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_wrong_code_args(t_cw *cw, t_crg *crg)
{
	char	tmp;
	char	code;
	int		shift;
	int		mask;
	int		count_args;

	crg->step = 0;
	shift = 6;
	mask = 0xC0;
	code = cw->map[crg->pc + 1];
	count_args = cw->op[crg->cur_op - 1].arg_nbrs + 1;
	while (--count_args)
	{
		tmp = (code & mask) >> shift;
		if (tmp == 0x1)
			crg->step = crg->step + REG_NUM_SIZE;
		else if (tmp == 0x2)
			crg->step = crg->step + (int)cw->op[crg->cur_op - 1].t_dir;
		else if (tmp == 0x3)
			crg->step = crg->step + IND;
		shift = shift - 2;
		mask = mask / 4;
	}
	crg->step = OP_NAME + (int)(cw->op[crg->cur_op - 1].need_arg_code)
	+ crg->step;
}

int		ft_check_REG_help(t_cw *cw, t_crg *crg)
{
	int		i;
	int		pc;

	i = 0;
	ft_parse_code_arg(cw, crg);
	crg->step = OP_NAME + (int)(cw->op[crg->cur_op - 1].need_arg_code);
	pc = (PC + crg->step) % MEM_SIZE;
	while (crg->args[i] != 0)
	{
		if (crg->args[i] == 1)
		{
			if (cw->map[pc] < 1 || cw->map[pc] > 16)
				return (-1);
			pc = (pc + REG_NUM_SIZE) % MEM_SIZE;
			crg->step = crg->step + REG_NUM_SIZE;
		}
		ft_check_help(cw, crg, &i, &pc);
		i++;
	}
	return (1);
}

void	ft_parse_code_arg(t_cw *cw, t_crg *crg)
{
	int		i;
	int		shift;
	int		mask;
	char	tmp;
	int		count_args;

	i = 0;
	shift = 6;
	mask = 192;
	count_args = cw->op[crg->cur_op - 1].arg_nbrs;
	ft_bzero(crg->args, 4 * sizeof(int));
	while (count_args)
	{
		tmp = (cw->map[(crg->pc + 1) % MEM_SIZE] & mask) >> shift;
		if (tmp == 0x1)
			crg->args[i] = 1;
		else if (tmp == 0x2)
			crg->args[i] = 2;
		else if (tmp == 0x3)
			crg->args[i] = 3;
		shift = shift - 2;
		mask = mask / 4;
		i++;
		count_args--;
	}
}

int		ft_valid_code_arg(t_cw *cw, t_crg *crg)
{
	int	i;
	int	pc;
	int	code_arg;

	i = 0;
	pc = (PC + 1) % MEM_SIZE;
	code_arg = cw->map[pc];
	if (cw->op[crg->cur_op - 1].need_arg_code == 0)
		return (1);
	crg->code_args = code_arg;
	ft_help_valid(cw, crg);
	ft_parse_code_arg(cw, crg);
	code_arg = crg->code_args;
	while (cw->op[crg->cur_op - 1].code_args[i])
	{
		if (code_arg == (unsigned char)cw->op[crg->cur_op - 1].code_args[i])
			if (ft_check_REG(cw, crg) == 1)
			{
				crg->code_args = cw->op[crg->cur_op - 1].code_args[i];
				return (cw->op[crg->cur_op - 1].code_args[i]);
			}
		i++;
	}
	return (-1);
}
