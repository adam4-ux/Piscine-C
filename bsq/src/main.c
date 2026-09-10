/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eadam <eadam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:58:51 by sfaraji           #+#    #+#             */
/*   Updated: 2026/09/10 23:45:23 by eadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	process_fd(int fd)
{
	char		*content;
	int			size;
	t_map		map;
	t_square	square;

	content = read_all(fd, &size);
	if (!content || !parse_map(content, size, &map))
	{
		print_error();
		free(content);
		return ;
	}
	free(content);
	square = solve_map(&map);
	fill_square(&map, square);
	print_map(&map);
	free_map(&map);
}

void	process_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_error();
		return ;
	}
	process_fd(fd);
	close(fd);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		process_fd(0);
	i = 1;
	while (i < argc)
	{
		process_file(argv[i]);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
