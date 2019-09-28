/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:04:49 by waddam            #+#    #+#             */
/*   Updated: 2019/09/28 20:43:03 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static int	ft_flag_n(char **argv, int argc, int *i, t_cw *cw)
{
	if (*i + 2 < argc)
	{

	}
	else
		return (0);
}

static void	ft_initialize(t_cw *cw)
{
	ft_bzero(cw, sizeof(t_cw));
	cw->cclt_die = CYCLE_TO_DIE;
}

int			ft_parse(int argc, char **argv, t_cw *cw)
{
	int		i;

	i = 1;
	if (argc <= 1)
	{
		printf("Too few arguments.\n");
		return (0);
	}
	ft_initialize(cw);
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-n") == 0)
			ft_flag_n(argv, argc, &i, cw);
		else if (ft_strcmp(argv[i], "-dump") == 0)
			ft_flag_dump(argv, argc, &i, cw);
		else if (ft_analyze_args(argv, argc, &i, cw) == 0)
			ft_write_plr(argv, &i, cw);
		else
			return (0);
	}
	return (1);
}