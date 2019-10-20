/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:23:06 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/20 15:52:12 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	terminate_parser(t_parser *parser)
{
	ft_strarrdel(&parser->file);
	ft_strdel(&parser->name);
	ft_strdel(&parser->code);
	ft_strdel(&parser->comment);
}
