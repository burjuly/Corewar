/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:12:35 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/23 20:28:44 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		code_of_type(t_token *token, uint32_t dest,
								uint8_t n_arg, char *bytecode)
{
	int8_t	res;
	int		arg;

	res = 0;
	arg = 0;
	while (arg < n_arg)
	{
		if (token->type == REGISTER)
			res |= 1 << 2 * (3 - arg++);
		else if (token->type == DIRECT || token->type == DIRECT_LABEL)
			res |= 2 << 2 * (3 - arg++);
		else if (token->type == INDIRECT || token->type == INDIRECT_LABEL)
			res |= 3 << 2 * (3 - arg++);
		token = token->next;
	}
	value_to_bytecode(bytecode, dest, res, 1);
}

void		fill_args_data(t_parser *par, uint32_t *dest, char *bytecode)
{
	int32_t	len;

	len = 0;
	if (par->head->type == REGISTER)
		len = T_REG;
	else if (par->head->type == DIRECT || par->head->type == DIRECT_LABEL)
		len = g_op[par->op].t_dir_size;
	else if (par->head->type == INDIRECT || par->head->type == INDIRECT_LABEL)
		len = 2;
	value_to_bytecode(bytecode, *dest, len, par->head->data);
	*dest += len;
	par->head = par->head->next;
}

void		filler_char_array(t_parser *par, uint32_t dest, char *bytec)
{
	while (par->head)
	{
		if (par->head->type == OPERATOR)
		{
			par->op = par->head->data;
			value_to_bytecode(bytec, dest, g_op[par->head->data].code, 1);
			++dest;
			if (g_op[par->head->data].args_types_code)
			{
				code_of_type(par->head, dest, g_op[par->op].args_num, bytec);
				++dest;
			}
			par->head = par->head->next;
		}
		else if (par->head->type == REGISTER || par->head->type == DIRECT ||
			par->head->type == INDIRECT || par->head->type == DIRECT_LABEL ||
				par->head->type == INDIRECT_LABEL)
			fill_args_data(par, &dest, bytec);
		else
			par->head = par->head->next;
	}
}

void		write_to_file(t_parser *parser)
{
	char	*bytecode;
	int32_t	position;

	position = 0;
	bytecode = ft_strnew(4 + PROG_NAME_LENGTH + 4 + 4 +
							COMMENT_LENGTH + 4 + parser->bytes);
	value_to_bytecode(bytecode, position, COREWAR_EXEC_MAGIC, 4);
	position += 4;
	ft_memcpy(&bytecode[position], parser->name, ft_strlen(parser->name));
	position += PROG_NAME_LENGTH;
	position += 4;
	value_to_bytecode(bytecode, position, parser->bytes, 4);
	position += 4;
	ft_memcpy(&bytecode[position], parser->comment,
				ft_strlen(parser->comment));
	position += COMMENT_LENGTH;
	position += 4;
	filler_char_array(parser, 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4,
						bytecode);
	write(parser->fd, bytecode, 4 + PROG_NAME_LENGTH + 4 + 4 +
							COMMENT_LENGTH + 4 + parser->bytes);
	ft_strdel(&bytecode);
}
