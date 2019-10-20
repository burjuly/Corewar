/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:21:44 by draudrau          #+#    #+#             */
/*   Updated: 2019/10/20 20:03:25 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_print_map(t_cw *cw)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != 0)
			ft_printf(" \n");
		if (i % 64 == 0 && i != (MEM_SIZE - 1))
			ft_printf("0x%04x :", i);
		if (i % 1 == 0)
			ft_printf(" ");
		ft_printf("%.2hhx", cw->map[i]);
		i++;
	}
	ft_printf(" \n");
}

void	ft_add_carriage(t_cw *cw, int k, int pc)
{
	t_crg	*start;
	t_crg	*new;

	start = cw->crg;
	if (start == NULL)
	{
		if (!(start = (t_crg *)malloc(sizeof(t_crg))))
			ft_leave("Error: Memory not allocated");
		ft_bzero(start, sizeof(t_crg));
		start->pc = pc;
		start->reg[0] = -k;
		start->next = NULL;
		cw->crg = start;
	}
	else
	{
		if (!(new = (t_crg *)malloc(sizeof(t_crg))))
			ft_leave("Error: Memory not allocated");
		ft_bzero(new, sizeof(t_crg));
		new->pc = pc;
		new->reg[0] = -k;
		new->next = start;
		cw->crg = new;
	}
	cw->count_crg++;
}

int		ft_search_next_plr(t_cw *cw, int num)
{
	int i;

	i = 0;
	while (i < cw->plr_nbrs)
	{
		if (cw->plr[i].num == num)
			return (i);
		i++;
	}
	return (0);
}

void	ft_add_plr_on_map(t_cw *cw)
{
	int		i;
	int		j;
	int		k;
	int		delta;

	i = 0;
	k = 1;
	delta = MEM_SIZE / cw->plr_nbrs;
	ft_memset(cw->map, 0, MEM_SIZE);
	ft_printf("Introducing contestants...\n");
	while (i < 4096 && k <= cw->plr_nbrs)
	{
		j = ft_search_next_plr(cw, k);
		if (j < cw->plr_nbrs)
			ft_memcpy(&(cw->map[i]), cw->plr[j].code, cw->plr[j].code_size);
		else
			break ;
		ft_add_carriage(cw, k, i);
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		j + 1, cw->plr[j].code_size, cw->plr[j].name, cw->plr[j].comment);
		i = i + delta;
		k++;
	}
	cw->last_plr = j + 1;
}

void	ft_map(t_cw *cw)
{
	ft_add_plr_on_map(cw);
}
