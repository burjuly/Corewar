/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:48:45 by waddam            #+#    #+#             */
/*   Updated: 2019/09/30 01:05:01 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

/*
** TODO
** close ft_write_data
*/

static void	ft_fill_plr(int fd, t_plr *plr)
{
	char	buf[4];
	int		code_size;

	if (read(fd, buf, 4) <= 0)
		ft_leave("ERROR. Incorrect champion structure");
	ft_byte_reverse(buf);
	if (*((int *)buf) - COREWAR_EXEC_MAGIC != 0)
		ft_leave("ERROR. The specified file is not a champion");
	if (read(fd, &(plr->name), PROG_NAME_LENGTH) <= 0)
		ft_leave("ERROR. Incorrect champion structure");
	if (read(fd, buf, 4) <= 0 && *((int *)buf) == 0)
		ft_leave("ERROR. Incorrect champion structure");
	if (read(fd, buf, 4) <= 0)
		ft_leave("ERROR. Incorrect champion structure");
	ft_byte_reverse(buf);
	plr->code_size = *((int *)buf);
	if (read(fd, &(plr->comment), COMMENT_LENGTH) <= 0)
		ft_leave("ERROR. Incorrect champion structure");
	if (read(fd, buf, 4) <= 0 && *((int *)buf) == 0)
		ft_leave("ERROR. Incorrect champion structure");
	if ((code_size = read(fd, &(plr->code), CHAMP_MAX_SIZE + 4)) <= 0)
		ft_leave("ERROR. Incorrect champion structure");
	if (code_size != plr->code_size || code_size > CHAMP_MAX_SIZE)
		ft_leave("ERROR. Incorrect champion structure");
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
		ft_leave("ERROR. Cannot open file");
}

void		ft_write_plr(char **argv, int *i, t_cw *cw, int pos)
{
	int		j;

	j = 0;
	while (cw->plr[j].name[0] != '\0')
		j++;
	if (j >= 4)
		ft_leave("ERROR. Too many champions");
	if (pos > 0)
	{
		cw->plr[j].flag_n = 1;
		cw->plr[j].num = pos;
	}
	else
		cw->plr[j].num = *i;
	cw->plr_nbrs++;
	ft_write_data(argv[*i], cw->plr + j);
}

void		ft_correct_plrs(t_cw *cw)
{
	int		i;
	int		flag_n[4];

	i = 0;
	ft_bzero(flag_n, sizeof(int) * 4);
	while (i < cw->plr_nbrs && cw->plr[i].name[0] != '\0')
	{
		if (cw->plr[i].flag_n == 1)
			flag_n[i] = cw->plr[i].num;
		i++;
	}
	i = 0;
	if (ft_check_repeat(flag_n, cw->plr_nbrs) == 1)
		ft_leave("ERROR. Repeat number of champion");
}
