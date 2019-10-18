/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_stuff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:25:49 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/09 17:46:16 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*parse_filename(int32_t argc, char **argv)
{
	char	*output_filename;
	char	*dot_pointer;

	output_filename = NULL;
	if (argc != 2)
		ft_error("usage: ./asm file.s");
	if (ft_chrcnt(argv[1], '.') == 0)
		return (NULL);
	dot_pointer = ft_strrchr(argv[1], '.');
	if (!ft_strequ(dot_pointer, ".s"))
		return (NULL);
	output_filename = ft_strnew(dot_pointer - argv[1] + 4);
	ft_strncpy(output_filename, argv[1], dot_pointer - argv[1] + 1);
	ft_strcat(output_filename, "cor");
	return (output_filename);
}

void		print_output_filename(char **filename)
{
	ft_putstr("\033[1;32mGenerate a champion at ");
	ft_putstr(*filename);
	ft_putendl("\033[0m");
	ft_strdel(filename);
}
