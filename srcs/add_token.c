/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:20:37 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/23 16:02:17 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		add_token(t_parser *parser, t_type type, char *str)
{
	t_token	*new;

	if (!parser->tokens)
	{
		parser->tokens = (t_token *)ft_memalloc(sizeof(t_token));
		parser->tokens->type = type;
		if (str)
			parser->tokens->content = ft_strdup(str);
		parser->head = parser->tokens;
	}
	else
	{
		while (parser->tokens->next)
			parser->tokens = parser->tokens->next;
		new = (t_token *)ft_memalloc(sizeof(t_token));
		new->type = type;
		if (str)
			new->content = ft_strdup(str);
		parser->tokens->next = new;
		parser->tokens = parser->tokens->next;
	}
}

void		add_label(t_parser *parser, t_token *token)
{
	t_label	*new;
	t_label	*head;

	if (!parser->labels)
	{
		parser->labels = (t_label *)ft_memalloc(sizeof(t_label));
		parser->labels->point = token;
	}
	else
	{
		head = parser->labels;
		while (head->next)
			head = head->next;
		new = (t_label*)ft_memalloc(sizeof(t_label));
		new->point = token;
		head->next = new;
		new->prev = head;
	}
}

void		push_back_token(t_parser *parser, char *str)
{
	t_token	*new;

	while (parser->tokens->next != NULL)
		parser->tokens = parser->tokens->next;
	new = (t_token *)ft_memalloc(sizeof(t_token));
	new->type = LABEL;
	if (str)
		new->content = ft_strsub(str, 0, ft_strlen(str) - 1);
	new->next = NULL;
	parser->tokens->next = new;
	parser->tokens = parser->tokens->next;
	parser->tokens->bytes = parser->bytes;
}

void		add_label_token(t_parser *parser, char *str)
{
	if (parser->tokens == NULL)
	{
		parser->tokens = (t_token *)ft_memalloc(sizeof(t_token));
		parser->tokens->type = LABEL;
		if (str)
			parser->tokens->content = ft_strsub(str, 0, ft_strlen(str) - 1);
		parser->tokens->next = NULL;
		parser->head = parser->tokens;
		parser->tokens->bytes = parser->bytes;
	}
	else
		push_back_token(parser, str);
	add_label(parser, parser->tokens);
}
