/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:23:00 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/23 16:19:10 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int32_t argc, char **argv)
{
	char	*output_filename;

	if (!(output_filename = parse_filename(argc, argv)))
		ft_error("ERROR: Invalid file name.");
	assemble(argv[1], output_filename);
	print_output_filename(&output_filename);
	exit(0);
}
