/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 13:37:44 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/20 15:28:20 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_parser(t_parser *parser)
{
	parser->column = 0;
	parser->row = 0;
	parser->fd = 0;
	parser->position = 0;
	parser->name = NULL;
	parser->code = NULL;
	parser->comment = NULL;
	parser->file = NULL;
}
