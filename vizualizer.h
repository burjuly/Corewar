/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:29:57 by abartole          #+#    #+#             */
/*   Updated: 2019/10/16 20:14:56 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZUALIZER_H
# define VIZUALIZER_H

#include "libft/libft.h"
#include <ncurses.h>

#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE


# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3


#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define M					MEM_SIZE
# define MEM(x) (((x) % (M)) < 0 ? (((x) % (M)) + (M)) : ((x) % (M)))

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

typedef struct 		s_op
{
	int				code_args[28];	// /0
	char			arg_nbrs;		// количество аргументов
	char			args[3];		// массив аргументов
	int				bef_op;			// "стоимость" в циклах
	char			need_arg_code;	// нужен ли код типов аргументов
	char			t_dir;		// использует T_DIR = 2
}					t_op;

typedef struct		s_plr
{
	int				num;						// номер игрока
	char			name[PROG_NAME_LENGTH + 1];	// имя
	int				code_size;					// размер его исполняемого кода
	char			comment[COMMENT_LENGTH + 1];	// комментарий
	char			code[CHAMP_MAX_SIZE + 1];	// сам код
	int				flag_n;						// наличие поданного с игроком флага -n
	int				lives;
}					t_plr;

typedef struct	s_vis
{
	WINDOW	*win[3];
	int		players;
	int		data[4];
}				t_vis;

typedef struct		s_crg
{
	int				pc;			// положение на карте (координата, индекс)
	int				carry;		// флаг carry
	int				reg[REG_NUMBER];	// регистры
	int				cur_op;		// код операции, на которой стоит каретка
	int				bef_op;		// количество циклов, оставшиеся до исполнения операции, на которой стоит каретка
	int				last_live;	// цикл, в котором в последний раз была выполнена операция live
	int				step;		// количество байт, которые нужно будет «перешагнуть», чтобы оказаться на следующей операции
	struct s_crg	*next;
	int				code_args;
	int				args[4];
}					t_crg;


typedef struct		s_cw
{
	t_vis			*cor;
	t_plr			plr[MAX_PLAYERS];	// массив структур типа "игрок"
	t_crg			*crg;				// указатель на список кареток
	t_op			op[16];				// масcив операций
	char			map[MEM_SIZE];		// карта
	int				plr_nbrs;	// количество игроков

	int				cycle_to_die;	// текущий cycle to die
	int				round;		// количество прошедших с начала игры циклов
	int				ctd_round;	// количество прошедших с последней проверки циклов
	int				checks;		// количество проверок
	int				dump;		// флаг dump (если > 0, тогда это номер цикла для dump)
	int				count_live;	// количество выполненных операций live за последний период, длинной в cycles_to_die
	int				last_plr;	// игрок, о котором в последний раз сказали, что он жив
	int				count_crg;
}					t_cw;

#define GAME_HEIGHT 68
#define GAME_WIDTH 196
#define INFO_HEIGHT 68
//#define INFO_WIDTH 196
#define INFO_WIDTH 55
#define MENU_HEIGHT 10
#define MENU_WIDTH 196

#define GAME 0
#define INFO 1
#define MENU 2

int		init_colors(void);

#endif
