/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:44:27 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/24 10:50:32 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	terminate_parser(t_parser *parser)
{
	t_token	*token;
	t_label	*label;

	ft_strarrdel(&(parser->file));
	ft_strdel(&(parser->comment));
	ft_strdel(&(parser->name));
	while (parser->tokens)
	{
		token = parser->tokens;
		parser->tokens = parser->tokens->next;
		ft_strdel(&(token->content));
		free(token);
		token = NULL;
	}
	while (parser->labels)
	{
		label = parser->labels;
		parser->labels = parser->labels->next;
		free(label);
		label = NULL;
	}
}
