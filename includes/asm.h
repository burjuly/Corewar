/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:42:39 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/23 19:18:00 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include "op_struct.h"

# include <fcntl.h>

typedef enum		e_type
{
	REGISTER = 1,
	DIRECT,
	DIRECT_LABEL,
	INDIRECT,
	INDIRECT_LABEL,
	COMMAND,
	STRING,
	LABEL,
	OPERATOR,
	SEPARATOR,
	NEW_LINE,
	END
}					t_type;

typedef struct		s_token
{
	char			*content;
	t_type			type;
	uint32_t		bytes;
	uint32_t		data;
	struct s_token	*next;
}					t_token;

typedef struct		s_label
{
	t_token			*point;
	struct s_label	*next;
	struct s_label	*prev;
}					t_label;

typedef struct		s_parser
{
	char			*name;
	char			*comment;
	char			**file;
	int32_t			fd;
	int32_t			flag;
	size_t			row;
	size_t			column;
	int32_t			bytes;
	int32_t			op;
	int32_t			arg;
	t_label			*labels;
	t_token			*tokens;
	t_token			*head;
}					t_parser;

/*
** file stuff
*/

char				*parse_filename(int32_t argc, char **argv);
void				print_output_filename(char **filename);
void				check_end_line(char *str);
void				read_file(t_parser *parser);

/*
** qoutes
*/

size_t				get_lenght(const t_parser *parser, size_t row,
								size_t column);
void				get_symbols(t_parser *parser, char **words);
char				*get_words_inside(t_parser *parser);

/*
** asm
*/

void				assemble(char *input_filename, char *output_filename);
void				parse(t_parser *parser);
void				parse_code(t_parser *parser);
void				skip_to_text(t_parser *parser);
void				create_token(t_parser *parser, size_t *column,
									int32_t *label);
void				make_new_token(t_parser *parser);
char				*check_oper(char *given_str, size_t *column);
void				add_token(t_parser *par, t_type type, char *str);
void				add_label_token(t_parser *parser, char *str);
void				push_back_token(t_parser *parser, char *str);
void				add_label(t_parser *parser, t_token *token);
void				next_parse_args(t_parser *parser, int i);
void				param_count(t_parser *parser, int32_t args, int32_t *i);
void				parse_args(t_parser *parser, int32_t i, int32_t args,
								size_t column);
void				check_args(char *string, t_parser *parser);

/*
** name and comment
*/

void				parse_name_and_comment(t_parser *parser);
void				new_name(t_parser *parser);
void				new_comment(t_parser *parser);
void				new_name_or_comment(t_parser *parser);

/*
** to file
*/

void				value_to_bytecode(char *data, int32_t pos,
										int32_t value, size_t size);
void				write_bytecode_to_file(t_parser *parser);
void				write_to_file(t_parser *parser);
void				convert_to_bytecode(t_parser *parser);
uint32_t			add_bytes(t_token *operator, char *label, t_parser *parser);
void				search_label(t_parser *parser, char *label);

/*
** errors
*/

void				ft_error(const char *message);
void				syntax_error(const size_t row, const size_t column);

/*
** utils
*/

int32_t				is_comment_char(const int c);
int32_t				label_or_comand(t_parser *parser, char *str,
										size_t *column);

#endif
