/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:11:34 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/20 15:52:07 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			assemble(char *input_filename, char *output_filename)
{
	t_parser	parser;

	init_parser(&parser);
	if ((parser.fd = open(input_filename, O_RDONLY)) == -1)
		ft_error("ERROR: Can't open given file.");
	parse(&parser);
	close(parser.fd);
	if ((parser.fd = open(output_filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		ft_error("ERROR: Can't create a file.");
	write_bytecode_to_file(&parser);
	close(parser.fd);
	terminate_parser(&parser);
}
