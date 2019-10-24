/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:48:45 by waddam            #+#    #+#             */
/*   Updated: 2019/10/24 03:27:20 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static void	ft_fill_plr(int fd, t_plr *plr)
{
	char	buf[4];
	int		code_size;

	if (read(fd, buf, 4) <= 0)
		ft_leave("Error: Incorrect champion structure");
	ft_byte_reverse(buf, 4);
	if (*((int *)buf) - COREWAR_EXEC_MAGIC != 0)
		ft_leave("Error: The specified file is not a champion");
	if (read(fd, &(plr->name), PROG_NAME_LENGTH) <= 0)
		ft_leave("Error: Incorrect champion structure");
	if (read(fd, buf, 4) <= 0 && *((int *)buf) == 0)
		ft_leave("Error: Incorrect champion structure");
	if (read(fd, buf, 4) <= 0)
		ft_leave("Error: Incorrect champion structure");
	ft_byte_reverse(buf, 4);
	plr->code_size = *((int *)buf);
	if (read(fd, &(plr->comment), COMMENT_LENGTH) <= 0)
		ft_leave("Error: Incorrect champion structure");
	if (read(fd, buf, 4) <= 0 && *((int *)buf) == 0)
		ft_leave("Error: Incorrect champion structure");
	if ((code_size = read(fd, &(plr->code), CHAMP_MAX_SIZE + 4)) <= 0)
		ft_leave("Error: Incorrect champion structure");
	if (code_size != plr->code_size || code_size > CHAMP_MAX_SIZE)
		ft_leave("Error: Incorrect champion structure");
}

static void	ft_write_data(char *name, t_plr *plr)
{
	int		fd;

	if ((fd = open(name, O_RDONLY)) != -1)
	{
		ft_fill_plr(fd, plr);
		close(fd);
	}
	else
		ft_leave("Error: Cannot open file");
}

void		ft_write_plr(char **argv, int *i, t_cw *cw, int pos)
{
	int		plr_nbrs;
	int		j;

	plr_nbrs = cw->plr_nbrs;
	j = 0;
	while (--plr_nbrs >= 0)
		j++;
	if (j >= 4)
		ft_leave("Error: Too many champions");
	cw->plr_nbrs++;
	if (pos > 0)
	{
		cw->plr[j].flag_n = 1;
		cw->plr[j].num = pos;
	}
	else
		cw->plr[j].num = cw->plr_nbrs;
	ft_write_data(argv[*i], cw->plr + j);
}

static void	ft_valid_plrs(t_plr *plr, int size)
{
	int		i;
	int		j;
	int		temp;

	i = -1;
	while (++i < size)
	{
		if (plr[i].flag_n == 1)
		{
			if (plr[i].num > size)
				ft_leave("Error: Bad arguments for the -n flag");
			temp = plr[i].num;
		}
		else
			continue ;
		j = 0;
		while (j < size)
		{
			if (plr[j].flag_n == 1 && temp == plr[j].num && j != i)
				ft_leave("Error: Repeat number of champion");
			j++;
		}
	}
}

void		ft_correct_plrs(t_cw *cw)
{
	int		i;

	i = 0;
	ft_valid_plrs(cw->plr, cw->plr_nbrs);
	ft_sort_plrs(cw->plr, cw->plr_nbrs);
}
