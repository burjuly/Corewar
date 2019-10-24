/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_bytecode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 12:34:32 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/23 22:14:25 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			value_to_bytecode(char *data, int32_t position,
								int32_t value, size_t size)
{
	int8_t		i;

	i = 0;
	while (size--)
	{
		data[position + size] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
	}
}

void			search_label(t_parser *parser, char *label)
{
	t_label		*head;

	head = parser->labels;
	while (head)
	{
		if (ft_strequ(head->point->content, label))
			return ;
		head = head->next;
	}
	ft_putendl(label);
	ft_error("ERROR: Invalid label.");
}

uint32_t		add_bytes(t_token *operator, char *label, t_parser *parser)
{
	uint32_t	cur_byte;
	uint32_t	label_byte;
	t_label		*head;

	head = parser->labels;
	cur_byte = operator->bytes;
	while (head->next)
	{
		if (ft_strequ(head->point->content, label))
			break ;
		head = head->next;
	}
	while (head->point->next && head->point->next->type != OPERATOR)
		head->point = head->point->next;
	if (head->point->next)
		label_byte = head->point->next->bytes;
	else
		label_byte = head->point->bytes;
	return (label_byte - cur_byte);
}

void			convert_to_bytecode(t_parser *parser)
{
	t_token		*operator;

	operator = NULL;
	while (parser->tokens)
	{
		if (parser->tokens->type == OPERATOR)
			operator = parser->tokens;
		else if (parser->tokens->type == INDIRECT_LABEL ||
				parser->tokens->type == DIRECT_LABEL)
		{
			search_label(parser, parser->tokens->content);
			parser->tokens->data = add_bytes(operator,
										parser->tokens->content, parser);
		}
		parser->tokens = parser->tokens->next;
	}
}

void			write_bytecode_to_file(t_parser *parser)
{
	parser->tokens = parser->head;
	convert_to_bytecode(parser);
	parser->tokens = parser->head;
	write_to_file(parser);
}
