/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:48:45 by waddam            #+#    #+#             */
/*   Updated: 2019/09/29 21:10:16 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

/*
** TODO
** safe read ft_check_mheader
** close ft_write_data
*/

static void ft_check_mheader(int fd)
{
	char	bytes_array[4];
	int		header;

	read(fd, &bytes_array[3], 1);
	read(fd, &bytes_array[2], 1);
	read(fd, &bytes_array[1], 1);
	read(fd, &bytes_array[0], 1);
	header = *((int *)bytes_array);
	if (header - COREWAR_EXEC_MAGIC != 0)
		ft_leave("ERROR. The specified file is not a champion");
}

static void ft_fill_plr(int fd, t_plr *plr)
{
	char	buf[4];
	int		code_size;

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

static void ft_write_data(char *chmp, t_plr *plr, int ind)
{
	int		fd;
	short	prog_size;

	if ((fd = open(chmp, O_RDONLY)) != -1)
	{
		ft_check_mheader(fd);
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
	while (cw->plr[j].name[0] != 0)
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
	ft_write_data(argv[*i], cw->plr, j);
}
