/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:41:54 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/09 17:30:45 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_parser		*init_parser(int32_t fd)
{
	t_parser	*parser;

	parser = (t_parser *)ft_memalloc(sizeof(t_parser));
	parser->fd = fd;
	return (parser);
}
