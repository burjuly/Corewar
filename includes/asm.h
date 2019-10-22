/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:42:39 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/22 21:59:09 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include "op_struct.h"

# include <fcntl.h>

typedef struct	s_parser
{
	char		*name;
	char		*comment;
	char		*code;
	char		**file;
	int32_t		fd;
	int32_t		position;
	int32_t		flag;
	size_t		row;
	size_t		column;
}				t_parser;


/*
** file stuff
*/

char			*parse_filename(int32_t argc, char **argv);
void			print_output_filename(char **filename);
void			check_end_line(char *str);
void			read_file(t_parser *parser);

/*
** qoutes
*/

size_t			get_lenght(const t_parser *parser, size_t row, size_t column);
void			get_symbols(t_parser *parser, char **words);
char			*get_words_inside(t_parser *parser);

/*
** asm
*/

void			assemble(char *input_filename, char *output_filename);
void			parse(t_parser *parser);
void			parse_code(t_parser *parser);
void			make_new_token(t_parser *parser);

/*
** name and comment
*/

void			parse_name_and_comment(t_parser *parser);
void			new_name(t_parser *parser);
void			new_comment(t_parser *parser);
void			new_name_or_comment(t_parser *parser);

/*
** t_parser
*/

void			init_parser(t_parser *parser);
void			terminate_parser(t_parser *parser);

/*
** converting to byte
*/

void			value_to_bytecode(char *data, int32_t pos,
									int32_t value, size_t size);
void			write_bytecode_to_file(const t_parser *parser);

/*
** errors
*/

void			ft_error(char *message);
void			syntax_error(size_t row, size_t column);

/*
** utils
*/

int				is_comment_char(int c);

#endif
