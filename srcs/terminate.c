/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:25:51 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/09 17:53:37 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	terminate_parser(t_parser **parser)
{
	ft_strdel(&(*parser)->name);
	ft_strdel(&(*parser)->comment);
	ft_strdel(&(*parser)->code);
	ft_memdel((void **)parser);
}
