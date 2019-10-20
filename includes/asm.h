/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:42:39 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/20 15:51:37 by cdraugr-         ###   ########.fr       */
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
	int32_t		fd;
	size_t		row;
	size_t		column;
	int32_t		position;
	char		*name;
	char		*comment;
	char		*code;
	char		**file;
}				t_parser;


/*
** filename stuff
*/

char			*parse_filename(int32_t argc, char **argv);
void			print_output_filename(char **filename);

/*
** asm
*/

void			assemble(char *input_filename, char *output_filename);
void			parse(t_parser *parser);
void			check_end_line(char *str);
void			read_file(t_parser *parser);

/*
** parser
*/

void			init_parser(t_parser *parser);
void			terminate_parser(t_parser *parser);

/*
** converting
*/

void			value_to_bytecode(char *data, int32_t pos,
									int32_t value, size_t size);
void			write_bytecode_to_file(const t_parser *parser);

/*
** error
*/

void			ft_error(char *message);

#endif
