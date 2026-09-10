/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eadam <eadam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:58:59 by sfaraji           #+#    #+#             */
/*   Updated: 2026/09/10 23:45:33 by eadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	find_header_end(char *content, int size)
{
	int	i;

	i = 0;
	while (i < size && content[i] != '\n')
		i++;
	if (i == size)
		return (-1);
	return (i);
}

int	allocate_grid(t_map *map)
{
	int	i;

	map->grid = malloc(sizeof(char *) * map->rows);
	if (!map->grid)
		return (0);
	i = 0;
	while (i < map->rows)
	{
		map->grid[i] = malloc(map->cols + 1);
		if (!map->grid[i])
		{
			map->rows = i;
			free_map(map);
			return (0);
		}
		i++;
	}
	return (1);
}

void	copy_grid(char *content, int start, t_map *map)
{
	int	row;
	int	col;
	int	pos;

	row = 0;
	pos = start;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->cols)
			map->grid[row][col++] = content[pos++];
		map->grid[row][col] = '\0';
		pos++;
		row++;
	}
}

int	parse_map(char *content, int size, t_map *map)
{
	int	header_end;
	int	rows;

	map->grid = NULL;
	if (!content || size <= 0)
		return (0);
	header_end = find_header_end(content, size);
	if (header_end < 0 || !parse_header(content, header_end, map))
		return (0);
	if (!validate_map_body(content, header_end + 1, size, map))
		return (0);
	rows = map->rows;
	if (!allocate_grid(map))
	{
		map->rows = rows;
		return (0);
	}
	copy_grid(content, header_end + 1, map);
	return (1);
}
