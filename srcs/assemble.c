/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:11:34 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/22 19:37:54 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			assemble(char *argv, char *output)
{
	t_parser	parser;
	char		*input;

	init_parser(&parser);
	input = ft_strtrim(argv);
	if ((parser.fd = open(input, O_RDONLY)) == -1)
		ft_error("ERROR: Can't open given file.");
	ft_strdel(&input);
	parse(&parser);
	close(parser.fd);
	if ((parser.fd = open(output, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		ft_error("ERROR: Can't create a file.");
	write_bytecode_to_file(&parser);
	close(parser.fd);
	terminate_parser(&parser);
}
