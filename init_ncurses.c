/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:37:57 by abartole          #+#    #+#             */
/*   Updated: 2019/10/17 21:06:18 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizualizer.h"

void	draw_carriage(t_cw *cw)
{
	t_crg	*crg;
	int		color;

	crg = cw->crg;
	while (crg)
	{
		crg->pc = (crg->pc % MEM_SIZE) < 0 ? (crg->pc % MEM_SIZE + MEM_SIZE) :
			(crg->pc % MEM_SIZE);
		wattron(cw->cor->win[GAME], COLOR_PAIR(color));
		mvwprintw(cw->cor->win[GAME], crg->pc / 64 + 1,
				2 + (crg->pc % 64) * 3, "%.2x",
				cw->map[crg->pc]);
		wattroff(cw->cor->win[GAME], COLOR_PAIR(color));
		crg = crg->next;
	}
	wrefresh(cw->cor->win[GAME]);
}

int		players(WINDOW *info, int line, t_cw *cw)
{
	int i;

	i = -1;
	while (++i < cw->cor->players)
	{
		wattron(info, COLOR_PAIR(cw->plr[i].num));
		mvwprintw(info, line++, 2, "Player %d : %s \n",
				cw->plr[i].num, cw->plr[i].name);
		wattroff(info, COLOR_PAIR(cw->plr[i].num));
		mvwprintw(info, line++, 4, "Lives in current period :\t\t%d    ",
				cw->plr[i].lives);
		line++;
	}
	return (line);
}

void	draw_game(WINDOW *game, t_cw *cw)
{
	int		i;
	int		j;
	int		line;
	int		col;

	line = 1;
	i = -1;
	while (++i < 64)
	{
		col = 2;
		j = -1;
		while (++j < 64)
		{
			wattron(game, COLOR_PAIR(13));
			mvwprintw(game, line, col, "%.2x ", cw->map[i * 64 + j]);
			wattroff(game, COLOR_PAIR(13));
			col += 3;
		}
		line++;
	}
	draw_carriage(cw);
}

void	draw_info(WINDOW *info, t_cw *cw)
{
	int line;

	line = 7;
	wattron(info, COLOR_PAIR(2));
	mvwprintw(info, 1, 2, "** RUNNING **");
	wattroff(info, COLOR_PAIR(2));
	mvwprintw(info, 3, 2, "Cycle : %d ", cw->round); //or ctd_round
	//mvwprintw(info, 5, 2, "Processes : %d ", cw->cor->players); //i need to know how many players are  in the game
	line = players(info, line, cw);
	mvwprintw(info, line, 2, "CYCLE_TO_DIE : %d ", cw->cycle_to_die);
	mvwprintw(info, line + 2, 2, "CYCLE_DELTA : %d ", CYCLE_DELTA);
}

void	init_screen(t_cw *cw)
{
	cw->cor->win[GAME] = newwin(66, 195, 1, 3);
	box(cw->cor->win[GAME], 0, 0);
	wrefresh(cw->cor->win[GAME]);
	cw->cor->win[INFO] = newwin(66, 56, 1, 200);
	box(cw->cor->win[INFO], 0, 0);
	wrefresh(cw->cor->win[INFO]);
	nodelay(cw->cor->win[GAME], 1);
	nodelay(cw->cor->win[INFO], 1);
	curs_set(0);
 	usleep(14000);
	draw_game(cw->cor->win[GAME], cw);
	draw_info(cw->cor->win[INFO], cw);
	box(cw->cor->win[GAME], 0, 0);
	box(cw->cor->win[INFO], 0, 0);
	wrefresh(cw->cor->win[GAME]);
	wrefresh(cw->cor->win[INFO]);
}

void	init_ncurces(t_cw *cw)
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	init_screen(cw);
}

void	end_of_game(t_cw *cw)
{
	wattron(cw->cor->win[INFO], COLOR_PAIR(4));
	mvwprintw(cw->cor->win[INFO], 1, 2, "** END OF THE GAME **");
	wattroff(cw->cor->win[INFO], COLOR_PAIR(4));
	wattron(cw->cor->win[INFO], COLOR_PAIR(1));
	mvwprintw(cw->cor->win[INFO], 32, 2, "Winner ->[%d] %s ",
			cw->last_plr, cw->plr[cw->last_plr].name);
	wattroff(cw->cor->win[INFO], COLOR_PAIR(1));
	wrefresh(cw->cor->win[INFO]);
	while (1)
		if (getch() == 32)
		{
			delwin(cw->cor->win[GAME]);
			delwin(cw->cor->win[INFO]);
			endwin();
			exit(1);
		}
}

int main(void)
{
	t_cw *cw;

	cw = ft_memalloc(sizeof(t_cw));
	cw->last_plr = 3;
	init_ncurces(cw);
	return (0);
}
