/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:11:34 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/09 18:36:08 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			assemble(char *input_filename, char *output_filename)
{
	int32_t		fd;
	t_parser	*parser;

	if ((fd = open(input_filename, O_RDONLY)) == -1)
		ft_error("ERROR: Can't open given file.");
	parser = init_parser(fd);
	// parse_file(fd, parser);
	if ((fd = open(output_filename, O_CREAT | O_TRUNC | O_WRONLY, 644)) == -1)
		ft_error("ERROR: Can't create a file.");
	// convert_to_bitcode(fd, parser);
	terminate_parser(&parser);
}
