/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:06:16 by draudrau          #+#    #+#             */
/*   Updated: 2019/10/08 16:44:53 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_print_crg(t_crg *crg)
{
	int		i = 0;

	while (i < 16)
	{
		printf("reg[%d] = %d\n", i, crg->reg[i]);
		i++;
	}
		printf("pc = %d\n", crg->pc);
		printf("carry = %d\n", crg->carry);
		printf("cur_op = %d\n", crg->cur_op);
		printf("bef_op = %d\n", crg->bef_op);
		printf("last_live = %d\n", crg->last_live);
		printf("step = %d\n", crg->step);
}

// 1	live
// 2	ld +
// 3	st +
// 4	add +
// 5	sub +
// 6	and +
// 7	or
// 8	xor
// 9	zjmp
// 10	ldi
// 11	sti
// 12	fork
// 13	lld
// 14	lldi
// 15	lfork
// 16	aff

void	ft_do_op(t_cw *cw, t_crg *crg)
{
	//crg->reg[0] = 15; // ПРОПИСЫВАЕМ РЕГИСТР ВРУЧНУЮ
	//crg->reg[1] = 63;
	//crg->reg[2] = 5;

	printf("ДО ОПЕРАЦИИ\n");
	ft_print_crg(crg);
	
	if (crg->cur_op == 1)
	{
		printf("ЗАШЛИ В ОПЕРАЦИЮ live\n");
		op_live(cw, crg);
	}
	else if (crg->cur_op == 2)
	{
		printf("ЗАШЛИ В ОПЕРАЦИЮ ld\n");
		op_ld(cw, crg);
	}
	else if(crg->cur_op == 3)
	{
		printf("ЗАШЛИ В ОПЕРАЦИЮ st\n");
		op_st(cw, crg);
	}
	else if(crg->cur_op == 4)
	{
		printf("ЗАШЛИ В ОПЕРАЦИЮ add\n");
		op_add(cw, crg);
	}
	else if(crg->cur_op == 5)
	{
		printf("ЗАШЛИ В ОПЕРАЦИЮ sub\n");
		op_sub(cw, crg);
	}
	else if (crg->cur_op == 6)
	{
		printf("ЗАШЛИ В ОПЕРАЦИЮ and\n");
		op_and(cw, crg);
	}
	else if(crg->cur_op == 7)
	{
		printf("ЗАШЛИ В ОПЕРАЦИЮ or\n");
		op_or(cw, crg);
	}
	else if(crg->cur_op == 8)
	{
		printf("ЗАШЛИ В ОПЕРАЦИЮ xor\n");
		op_xor(cw, crg);
	}
	else if(crg->cur_op == 9)
	{
		printf("ЗАШЛИ В ОПЕРАЦИЮ zjmp\n");
		op_zjmp(cw, crg);
	}
	else if(crg->cur_op == 10)
	{
		printf("ЗАШЛИ В ОПЕРАЦИЮ ldi\n");
		op_ldi(cw, crg);
	}
	// else if(crg->cur_op == 11)
	// {
	// 	printf("ЗАШЛИ В ОПЕРАЦИЮ sti\n");
	// 	op_sti(cw, crg);
	// }
	else if(crg->cur_op == 12)
	{
		printf("ЗАШЛИ В ОПЕРАЦИЮ fork\n");
		op_fork(cw, crg);
	}
	// else if(crg->cur_op == 13)
	// {
	// 	printf("ЗАШЛИ В ОПЕРАЦИЮ lld\n");
	// 	op_lld(cw, crg);
	// }
	else if(crg->cur_op == 14)
	{
		printf("ЗАШЛИ В ОПЕРАЦИЮ lldi\n");
		op_lldi(cw, crg);
	}
	// else if(crg->cur_op == 15)
	// {
	// 	printf("ЗАШЛИ В ОПЕРАЦИЮ lfork\n");
	// 	op_lfork(cw, crg);
	// }
	// else if(crg->cur_op == 16)
	// {
	// 	printf("ЗАШЛИ В ОПЕРАЦИЮ aff\n");
	// 	op_aff(cw, crg);
	// }

	printf("ПОСЛЕ ОПЕРАЦИИ\n");
	ft_print_map(cw);
	ft_print_crg(crg);
	exit(0);
}







/*
** Важно, чтобы во время цикла все описанные проверки и действия выполнялись строго
** в указанной последовательности.
** Поскольку за один цикл одна и та же каретка может получить новый код операции и
** установить количество циклов до её исполнения. А также уменьшить это количество
** на единицу.
** Если бы существовала операция со всего одним циклом ожидания, то она также была
** бы выполнена во время этого одного цикла.
**
** "if" работают
**        парами первый и второй, либо второй и третий (поэтому не else)
**        либо только в второй
*/
void	ft_do_cycle(t_cw *cw)
{
	t_crg	*crg;
	int		valid;

	crg = cw->crg;
	while (crg != NULL)
	{
		// printf("\n\nNEXT CYCLE\n\n");
		// самый первый ход в игре => картеки пусты (коммент в кукбук)
		// т.е crg->cur_op = 0, bef_op = 0, pc = 0

		// 1) Устанавливаем код операции
			// Если во время прошлого цикла каретка передвигалась ...
		if (crg->bef_op == 0)     // Перемещение имело место быть
		{

			crg->cur_op = cw->map[crg->pc];    // Узнать код операции = считать байт, на котором находится каретка
			// Если полученное число соответствует коду реальной операции, то его необходимо запомнить
			// Запомнили на предыдущем этапе тк там повтор по тексту, поэтому можно и так
			if (crg->cur_op > 0 && crg->cur_op <= 16)
				crg->bef_op = cw->op[crg->cur_op - 1].bef_op;    // также нужно установить значение переменной, которая хранит количество циклов до исполнения операции.
				// crg->bef_op = g_op_tab[crg->cur_op - 1].bef_op;    // также нужно установить значение переменной, которая хранит количество циклов до исполнения операции.
			// Если считанное число не попадает в диапазон [0x01; 0x10],
			// то есть полученный код указывает на несуществующую операцию.
			// В этом случае необходимо запомнить считанный код, а значение переменной,
			// хранящей количество циклов до выполнения, оставить равным нулю (все уже сделано).
		}
		// printf("GAME after IF #1\n");
		// ft_print_crg(crg);
		// 2) Уменьшить количество циклов до исполнения
			// Если количество циклов до выполнения, которое хранит соответствующая переменная в каретке, больше нуля
		if (crg->bef_op > 0)
			(crg->bef_op)--;
		// printf("GAME after IF #2\n");
		// ft_print_crg(crg);
		// 3) Выполнить операцию
			// Если количество циклов до исполнения равно нулю ...
		if (crg->bef_op == 0)
		{
			if (crg->cur_op > 0 && crg->cur_op <= 16)    // Если хранящийся код соответствует существующей операции ...
			{
				valid = 1;
				//valid = ft_valid_arg_and_reg(cw->map[crg->pc + 1]);    // тогда необходимо проверить на валидность код содержащий типы аргументов.
				if (valid > 0)    // Если данный код корректен и указывает, что среди аргументов операции есть регистр, необходимо также убедиться в корректности номера регистра. (регистры проверили на предыдущем шаге)
				{
					ft_do_op(cw, crg);    // Если все необходимые проверки были успешно пройдены, нужно выполнить операцию ...
					//  (crg->pc)++;    // и передвинуть каретку на следующую позицию. (в ft_do_op она проедет до последнего байта операции)
				}
				//else    // Если с самим кодом все нормально, но код типов аргументов или же номер регистра ошибочен ...
				//    crg->pc += ft_skip_step(cw->op[crg->cur_op - 1], cw->map[crg->pc + 1]);    // нужно пропустить данную операцию вместе с кодом типов аргументов и самими аргументами.
			}
			else    // Если же код операции ошибочен ...
				(crg->pc)++; // необходимо просто переместить каретку на следующий байт.
		}
		// printf("GAME after IF #3\n");
		// ft_print_crg(crg);
		crg = crg->next;
	}
}

void	ft_del_carriage(t_cw *cw, t_crg *cur, t_crg *prev)
{
	t_crg	*tmp;

	tmp = NULL;
	if (prev == NULL) // Если удаляемая каретка первая в списке
	{
		cw->crg = cur->next;
		tmp = cur;
		cur = cw->crg;
		free(tmp);
	}
	else
	{
		tmp = cur->next;
		free(cur);
		prev->next = tmp;
	}
}

static void	ft_check(t_cw *cw)
{
	t_crg	*curren_crg;
	t_crg	*prev_crg;

	curren_crg = cw->crg;
	prev_crg = NULL;
	cw->checks++;
	while (curren_crg != NULL)
	{
		if (curren_crg->last_live > cw->c_to_die)
		{
			ft_del_carriage(cw, curren_crg, prev_crg);  // Доделать!
		}
		if (cw->count_live >= NBR_LIVE)
			cw->c_to_die = cw->c_to_die - CYCLE_DELTA;

		prev_crg = curren_crg;
		curren_crg = curren_crg->next;
	}
}

void		ft_start_game(t_cw *cw)
{
	t_crg	*crg;

	while (cw->crg != NULL)
	{
		if (cw->c_to_die > 0)
		{
			crg = cw->crg;
			while (cw->round < cw->c_to_die)
			{
				ft_do_cycle(cw);
				cw->round++;
			}
		}
		else // конец игры ?
		{
			ft_do_cycle(cw);
			cw->round++;
		}
		ft_check(cw);
	}
}
