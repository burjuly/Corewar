/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:04:49 by waddam            #+#    #+#             */
/*   Updated: 2019/09/29 00:42:01 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"
// TODO корректный переход по i (провалидировали - сдвинули)
static void	ft_flag_n(int argc, char **argv, int *i, t_cw *cw)
{
	int		pos;

	if (*i + 2 < argc)
	{
		(*i)++;
		if (ft_strlen(argv[*i]) > 1 || ft_isdigit(argv[*i][0]) == 0)
			ft_leave("ERROR. Bad arguments for the -n flag");
		pos = ft_atoi(argv[*i]);
		if (pos > MAX_PLAYERS)
			ft_leave("ERROR. Bad arguments for the -n flag \
(set incorrect number for next player)");
// 		if (ft_analyze_chmp(argv, (*i)++) != 0)
// 			ft_leave("ERROR. Bad arguments for the -n flag \
// (incorrect champion format)");
// 		ft_write_plr(argv, *i, cw);
		(*i)++;
	}
	else
		ft_leave("ERROR. Bad arguments for the -n flag");
}

static void	ft_flag_dump(int argc, char **argv, int *i, t_cw *cw)
{

}

static void	ft_write_plr(char **argv, int *i, t_cw *cw)
{

}

static int	ft_analyze_chmp(char **argv, int *i)
{
	size_t	len;

	if ((len = ft_strlen(argv[*i])) <= 4)
		return (1);
	return (ft_strcmp(argv[*i + len - 4], ".cor"));
}

void		ft_parse(int argc, char **argv, t_cw *cw)
{
	int		i;

	i = 1;
	if (argc <= 1)
		ft_leave("ERROR. Too few arguments.\n\
usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...");
	ft_initialize(cw);
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-n") == 0)
			ft_flag_n(argc, argv, &i, cw);
		else if (ft_strcmp(argv[i], "-dump") == 0)
			ft_flag_dump(argc, argv, &i, cw);
		if (ft_analyze_chmp(argv, &i) == 0)
			ft_write_plr(argv, &i, cw);
		else
			ft_leave("ERROR. Bad input.\n\
usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...");
	}
}
