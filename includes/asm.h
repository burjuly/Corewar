/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:42:39 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/09 17:26:59 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
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

/*
** parser
*/

t_parser		*init_parser(int32_t fd);
void			terminate_parser(t_parser **parser);

/*
** error
*/

void			ft_error(char *message);

#endif
