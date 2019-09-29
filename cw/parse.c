/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:04:49 by waddam            #+#    #+#             */
/*   Updated: 2019/09/30 01:01:56 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

/*
** TODO
** корректный переход по i (провалидировали - сдвинули)
** сделать ft_analyze_plr - универсальной (путь не путь - работает)
*/

static int	ft_analyze_plr(char **argv, int *i)
{
	size_t	len;
	char	*path_plr;
	char	*name_plr;

	path_plr = argv[*i];
	name_plr = ft_strrchr(path_plr, '/');
	if (name_plr == NULL)
		return (1);
	name_plr++;
	if ((len = ft_strlen(name_plr)) <= 4)
		return (1);
	return (ft_strcmp(name_plr + len - 4, ".cor"));
}

static void	ft_flag_n(int argc, char **argv, int *i, t_cw *cw)
{
	int		pos;

	if (*i + 2 < argc)
	{
		(*i)++;
		if (ft_strlen(argv[*i]) > 1 || ft_isdigit(argv[*i][0]) == 0)
			ft_leave("ERROR. Bad arguments for the -n flag");
		pos = ft_atoi(argv[*i]);
		if (pos > MAX_PLAYERS || pos < 1)
			ft_leave("ERROR. Bad arguments for the -n flag \
(set incorrect number for player)");
		(*i)++;
		if (ft_analyze_plr(argv, i) != 0)
			ft_leave("ERROR. Bad arguments for the -n flag \
(incorrect champion format)");
		ft_write_plr(argv, i, cw, pos);
	}
	else
		ft_leave("ERROR. Bad arguments for the -n flag");
}

static void	ft_flag_dump(int argc, char **argv, int *i, t_cw *cw)
{
	int		j;

	j = 0;
	if (*i + 1 < argc)
	{
		(*i)++;
		while (argv[*i][j] != '\0')
		{
			if (ft_isdigit(argv[*i][j]) == 0)
				ft_leave("ERROR. Bad arguments for the -dump flag \
(set incorrect dump)");
			j++;
		}
		cw->dump = ft_atoi(argv[*i]);
	}
	else
		ft_leave("ERROR. Bad arguments for the -dump flag");
}

void		ft_parse(int argc, char **argv, t_cw *cw)
{
	int		i;

	i = 1;
	if (argc <= 1)
		ft_leave("ERROR. Too few arguments.\n\
Usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...");
	ft_initialize(cw);
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-n") == 0)
			ft_flag_n(argc, argv, &i, cw);
		else if (ft_strcmp(argv[i], "-dump") == 0)
			ft_flag_dump(argc, argv, &i, cw);
		else if (ft_analyze_plr(argv, &i) == 0)
			ft_write_plr(argv, &i, cw, 0);
		else
			ft_leave("ERROR. Bad input.\n\
Usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...");
		i++;
	}
	ft_correct_plrs(cw);
}
