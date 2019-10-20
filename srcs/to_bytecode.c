/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_bytecode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 12:34:32 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/20 14:41:11 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		value_to_bytecode(char *data, int32_t pos,
								int32_t value, size_t size)
{
	int8_t	i;

	i = 0;
	while (size--)
	{
		data[pos + size] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
	}
}

void		write_bytecode_to_file(const t_parser *parser)
{
	int32_t	len;
	int32_t	position;
	char	*bytecode;

	position = 0;
	len = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4 + parser->position;
	bytecode = ft_strnew((size_t)len);
	value_to_bytecode(bytecode, position, COREWAR_EXEC_MAGIC, 4);
	position += 4;
	// ft_memcpy(&bytecode[position], parser->name, ft_strlen(parser->name));
	position += PROG_NAME_LENGTH;
	position += 4;
	value_to_bytecode(bytecode, position, parser->position, 4);
	position += 4;
	// ft_memcpy(&bytecode[position], parser->comment, ft_strlen(parser->comment));
	position += COMMENT_LENGTH;
	position += 4;
	// ft_memcpy(&bytecode[position], parser->code, (size_t)parser->position);
	write(parser->fd, bytecode, (size_t)len);
	ft_strdel(&bytecode);
}
